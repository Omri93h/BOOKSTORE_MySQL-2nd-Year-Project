#include "database.h"

MySQL :: MySQL()
{
	row = NULL;
	res_set = nullptr;
	i = 0;
    connect = mysql_init(NULL);
    if ( !connect )
        cout << "MySQL Initialization Failed";
    connect = mysql_real_connect(connect, SERVER, USER, PASSWORD, DATABASE, 0,NULL,0);
    if ( connect )
        cout << "Connection Succeeded\n";
    else
        cout << "Connection Failed\n";
}


void MySQL::ShowTables()
{
	mysql_query(connect, "show tables");
	i = 0;

	res_set = mysql_store_result(connect);

	unsigned int numrows = mysql_num_rows(res_set);

	cout << "Tables in *" << DATABASE << "* database:" << endl;

	while (((row = mysql_fetch_row(res_set)) != NULL))
	{
		cout << row[i] << endl;
	}

}

std::string MySQL ::getParam()
{
	std::string param;
	std::getline(std::cin, param);
	return ("'" + param + "'");
}

int MySQL::askNameOrID()
{
	int by_param = 0;
	std::cout << RESET << "1. by ID\n2. by First&Last Name" << CYAN << endl;
	for (cin >> by_param; by_param != 1 && by_param != 2; cin >> by_param)
		std::cout << RED << "Wrong Parameter " << by_param << "!, Try Again:" << CYAN << endl;
	return by_param;
}

std::string MySQL::getDate(std::string date_num)
{
	std::string date;
	int param = 0;
	std::cout << MAGENTA << "Enter the " << date_num << " Date" << RESET << endl;
	
	// day
	std::cout << RESET <<"Day (example -> 10): " << CYAN;
	for (std::cin >>  param; param < 1 || param > 31 ; std::cin >> param)
		std::cout << RED << "Day Can't Be " << param << "!, Try Again:" << CYAN << endl;
	date = "-" + std::to_string(param);

	// month
	std::cout << RESET << "Month (example -> 1): " << CYAN;
	std::cin.ignore();
	for (std::cin >> param; param < 1 || param > 12; std::cin >> param)
		std::cout << RED << "Month Can't Be " << param << "!, Try Again:" << CYAN << endl;
	date = "-" + std::to_string(param) + date;

	// year
	std::cout << RESET << "Year (example -> 2015): " << CYAN;
	std::cin.ignore();
	for (cin >> param; param < 1990 || param > 2020; std::cin >> param)
		std::cout << RED << "Year Can't Be " << param << "!, Try Again: " << CYAN << endl;
	date = "" + std::to_string(param) + date;
	system("CLS");
	return date;
}


void MySQL :: loopRows(std::string result_title, std::string query, std::string after_result_str = "")
{
	mysql_query(connect, query.c_str());

	i = 0;

	res_set = mysql_store_result(connect);

	unsigned int numrows = mysql_num_rows(res_set);
	int numfields = mysql_num_fields(res_set);
	cout << BLUE << result_title;
	if (after_result_str == "")
		std::cout << endl << endl;
	while ((row = mysql_fetch_row(res_set)))
	{
		for (i = 0; i < numfields; i++)
		{
			if (row[i] == NULL)
				throw "\rNo values founded with the parameters given";
			cout << GREEN << row[i];
			if (after_result_str == "")
				cout << "\t\t";
			else
				cout << BLUE << after_result_str;
		}
		std::cout << "\n";
	}
	std::cout << RESET;
}

// ----------------------------------- QUERIES: ------------------------------------ //

void MySQL::bookInInventory()			// 1
{
	cout << RESET << "Enter The Book Name : ";
	string book_name = getParam();
	string query1 = "select title from book where title = ";
	string final_query = query1 + book_name;
	mysql_query(connect, final_query.c_str());
	res_set = mysql_store_result(connect);
	row = mysql_fetch_row(res_set);
	if (row)
		cout << GREEN << book_name + " is IN stock " <<  RESET << endl;
	else
		cout << RED << book_name + " is NOT in stock " << RESET << endl;

	return;
}


void MySQL::oldestCustomer()			// 2
{
	loopRows("The Oldest Client Is :","SELECT first_name, last_name FROM customer WHERE date_join = "
	"(SELECT MIN(date_join) FROM customer)");
}


void MySQL::oldestBookInStock()			// 3
{
	loopRows("The Oldest book in stock is :","SELECT title FROM book WHERE book_id = "
		"(SELECT book_id FROM inventory WHERE date_out IS NULL "
		"AND date_in = (SELECT MIN(date_in) FROM inventory))");
}


void MySQL::showOrders()				// 4
{
	loopRows("Current Orders:\n",
		"SELECT book.title, customer.first_name, customer.last_name, orders.date_order "
		"FROM orders INNER JOIN book ON orders.book_id = book.book_id "
		"INNER JOIN customer ON customer.customer_id = orders.customer_id "
		"ORDER BY orders.date_order");
}


void MySQL::bookPurchases()				// 5
{
	cout << RESET << "Enter The Book Name : ";
	std::string book_name = getParam();
	std::string query = "SELECT COUNT(*) FROM inventory i INNER JOIN book b ON i.book_id = b.book_id "
		"INNER JOIN author a ON a.book_id = i.book_id WHERE b.title = "
		+ book_name +
		" AND i.deal_id IS NOT NULL ";
	loopRows("The book " + book_name + " sold ", query, " times");
}

void MySQL::mostReadedAuthorByDates()	// 6
{
	std::string date_start = getDate("FIRST");
	std::string date_end = getDate("SECOND");
	std::string query = "SELECT a.first_name, a.last_name, COUNT(*) "
		"FROM inventory i INNER JOIN book b ON i.book_id = b.book_id "
		"INNER JOIN author a ON a.book_id = i.book_id "
		"INNER JOIN deal d ON d.deal_id = i.deal_id "
		"WHERE i.deal_id IS NOT NULL AND d.date_deal BETWEEN '"
		+ date_start + "' AND '" + date_end +
		"' GROUP BY a.first_name, a.last_name "
		"ORDER BY COUNT(*) DESC LIMIT 1";
	loopRows("The most readed Author from " + date_start + " to " + date_end + " is:", query);
}


void MySQL::topThreeBuyers()			// 7
{
	std::string query = "SELECT c.first_name, c.last_name, COUNT(*) "
		"FROM deal d INNER JOIN customer c ON c.customer_id = d.customer_id "
		"GROUP BY c.first_name , c.last_name ORDER BY COUNT(*) DESC LIMIT 3";
	loopRows("The Top 3 buying customers are:", query);
}


void MySQL::mostTranslations()			// 8
{
	std::string query = "SELECT title, COUNT(DISTINCT lang) FROM book "
		"GROUP BY title ORDER BY COUNT(*) DESC LIMIT 1";
	loopRows("The book which has the most translations is: ", query);
}


void MySQL::customerPurchaseHistory()	// 9
{
	std::string query = "SELECT d.date_deal,i.price, b.title  "
		"FROM customer c "
		"INNER JOIN deal d ON c.customer_id = d.customer_id "
		"INNER JOIN inventory i ON i.deal_id = d.deal_id "
		"INNER JOIN book b ON b.book_id = i.book_id WHERE ";

	int by_param = askNameOrID();

	if (by_param == 1)
	{
		cout << RESET << "Customer ID (example -> 5):" << CYAN << endl;
		cin.ignore();
		int customer_id;
		std::cin >> customer_id;
		query += "d.customer_id = " + std::to_string(customer_id);
		loopRows("Customer no. " + std::to_string(customer_id) + " Purchase History: ", query + " ORDER BY d.date_deal");
	}
	else
	{
		cout << RESET << "Customer First Name (example -> Ronni):" << CYAN << flush << endl;
		cin.ignore();
		std::string first_name = getParam();
		cout << RESET << "Customer Last Name (example -> Feldman):" << CYAN << flush << endl;
		std::string last_name = getParam();
		query += ("c.first_name = " + first_name) + (" AND ") + ("c.last_name = " + last_name);
		loopRows(first_name + " " + last_name + " Purchase History: ", query + " ORDER BY d.date_deal");
	}
}


void MySQL::customerOrderHistory()		// 10
{
	std::string query = "SELECT o.date_order, b.title, o.order_status FROM orders o "
		"INNER JOIN customer c ON c.customer_id = o.customer_id "
		"INNER JOIN book b ON o.book_id = b.book_id WHERE ";

	int by_param = askNameOrID();

	if (by_param == 1)
	{
		cout << RESET << "Customer ID (example -> 5):" << CYAN << endl;
		cin.ignore();
		int customer_id;
		std::cin >> customer_id;
		query += "o.customer_id = " + std::to_string(customer_id);
		loopRows("Customer no. " + std::to_string(customer_id) + " Orders History: ", query + " ORDER BY date_order");
	}
	else
	{
		cout << RESET << "Customer First Name (example -> Ronni):" << CYAN << flush << endl;
		cin.ignore();
		std::string first_name = getParam();
		cout << RESET << "Customer Last Name (example -> Feldman):" << CYAN << flush << endl;
		std::string last_name = getParam();
		query += ("c.first_name = " + first_name) + (" AND ") + ("c.last_name = " + last_name);
		loopRows(first_name + " " + last_name + " Orders History: ", query + " ORDER BY date_order");
	}
}


void MySQL::calculateShipping()			// 11
{
	int total, book_id;
	std::string	query = "SELECT method_name, kg_price* (SELECT SUM(weight) "
		"FROM book b WHERE b.book_id IN(";		
	std::string books = "";
	std::cout << RESET << "Amount of books to calculate(example -> 3)" << CYAN << endl;
	
	std::cin >> total;
	for (int i = 0; i < total; i++ )
	{
		std::cout << "\tBook ID " << i + 1 <<"/" << total << " :(example -> 5) ";
		std::cin >> book_id;
		books += std::to_string(book_id);
		if (i + 1 != total)
			books += ',';
	}
	query += books + ")) AS total_shipping_price FROM shipping_method";
	loopRows("\nShipping cost for books ID " + books, query);
}


void MySQL::splittedDeliveries()		// 12
{
	std::string query = "SELECT deal.date_deal, deal.deal_id, del.price, del_status,del.tracking_num "
		"FROM deal INNER JOIN delivery del ON deal.deal_id = del.deal_id WHERE deal.deal_id IN "
		"(SELECT deal.deal_id FROM deal INNER JOIN delivery del ON deal.deal_id = del.deal_id "
		"INNER JOIN customer c ON deal.customer_id = c.customer_id WHERE ";

	cout << RESET << "Customer First Name (example -> Garrik):" << CYAN << flush << endl;
	std::string first_name = getParam();
	cout << RESET << "Customer Last Name (example -> Mozes):" << CYAN << flush << endl;
	std::string last_name = getParam();

	query += ("c.first_name = " + first_name) + (" AND ") + ("c.last_name = " + last_name);
	query += " GROUP BY deal.deal_id HAVING COUNT(deal.deal_id) > 1) ORDER BY date_deal";
	loopRows(first_name + ' ' + last_name + " Splitted Deliveires:", query);
}


void MySQL::deliveryStatus()			// 13
{
	std::string query = "SELECT del.del_status, del.address FROM delivery del "
		"INNER JOIN deal ON deal.deal_id = del.deal_id "
		"INNER JOIN customer c ON c.customer_id = deal.customer_id "
		"WHERE deal.date_deal = '";

	std::string date = getDate("Deal");
	query += date + ("' AND ");

	std::cout << RESET << "Customer First Name (example -> Moshe):" << CYAN << flush <<endl;
	cin.ignore();
	std::string first_name = getParam();
	std::cout << RESET << "Customer Last Name (example -> Reuveny):" << CYAN << flush << endl;
	std::string last_name = getParam();

	query += ("c.first_name = " + first_name) + (" AND ") + ("c.last_name = " + last_name);

	loopRows(first_name + ' ' + last_name + ' ' + date + " Delivery Status: ", query);
}


void MySQL::totalByXpress()				// 14
{
	int month, year;

	// month
	std::cout << RESET << "Month (example -> 3): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2015): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	std::string query = "SELECT xpress FROM expenses WHERE MONTH(date_ex) = " + 
		std::to_string(month) +" AND YEAR(date_ex) =" + std::to_string(year);
	system("CLS");
	std::string query_title = "Total delivery payments to Xpress from " + to_string(month) +
		'/' + to_string(year) + " to ";
	if (month == 12)
		query_title += to_string(month - 11) + '/' + to_string(year + 1) + ':';
	else
		query_title += to_string(month + 1) + '/' + to_string(year) + ':';

	loopRows(query_title, query);
}


void MySQL::incomeFromBit()				// 15
{
	int month, year;

	// month
	std::cout << RESET << "Month (example -> 2): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2016): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	std::string query = "SELECT SUM(total_price) FROM deal WHERE payment_type = 'Bit' AND MONTH(date_deal) =" +
		std::to_string(month) + " AND YEAR(date_deal) =" + std::to_string(year);
	system("CLS");
	std::string query_title = "Total \"Bit\" income, from " + to_string(month) +
		'/' + to_string(year) + " to ";
	if (month == 12)
		query_title += to_string(month - 11) + '/' + to_string(year + 1) + ':';
	else
		query_title += to_string(month + 1) + '/' + to_string(year) + ':';
		
	loopRows(query_title, query);
}

void MySQL::aboveAvgDeals()				// 16
{
	std::string query = "SELECT i.deal_id, SUM(i.price - i.cost) AS book_profit "
		"FROM inventory i INNER JOIN deal d ON i.deal_id = d.deal_id "
		"WHERE i.deal_id IS NOT NULL AND d.date_deal >= DATE_SUB(NOW(), INTERVAL 12 MONTH) "
		"GROUP BY i.deal_id HAVING (SELECT AVG(book_profit) AS average "
		"FROM (SELECT i.deal_id, SUM(i.price - i.cost) AS book_profit FROM inventory i "
		"INNER JOIN deal d ON i.deal_id = d.deal_id WHERE i.deal_id IS NOT NULL "
		"AND d.date_deal >= DATE_SUB(NOW(), INTERVAL 12 MONTH) GROUP BY i.deal_id) "
		"AS inner_query) < book_profit";
	loopRows("Above average deals in the past 12 month:", query);
}


void MySQL::israelPostAndXpress()		// 17
{
	std::string query = "SELECT s_m.company,count(*) FROM deal d "
		"INNER JOIN delivery del ON d.deal_id = del.deal_id "
		"INNER JOIN shipping_method s_m ON s_m.method_id = del.method_id "
		"WHERE d.date_deal  >= date_sub(NOW(), INTERVAL 12 MONTH) "
		"GROUP BY company";
	loopRows("total Israel Post & Xpress deliveries in the past 12 month:", query);
}


void MySQL::diffEditionSameDelivery()	// 18
{
	std::string query = "SELECT d.date_deal, del.del_id, del.del_status, del.price,del.tracking_num "
		"FROM delivery_book d_b INNER JOIN book b ON b.book_id = d_b.book_id "
		"INNER JOIN delivery del ON del.del_id = d_b.del_id INNER JOIN deal d ON d.deal_id = del.deal_id "
		"GROUP BY b.title , del.tracking_num HAVING COUNT(b.title) > 1 "
		"AND COUNT(del.tracking_num) > 1 ORDER BY d.date_deal";
	loopRows("Deliveries with 2 or more editions of the same book:", query);

}


void MySQL::notReturningCustomers()		// 19
{
	std::string query = "SELECT c.first_name, c.last_name, d.date_deal FROM customer c "
		"INNER JOIN deal d ON c.customer_id = d.customer_id "
		"WHERE d.date_deal <= (NOW() - INTERVAL 24 MONTH) AND c.customer_id "
		"NOT IN( SELECT c.customer_id FROM customer c INNER JOIN deal d ON c.customer_id = d.customer_id "
		"WHERE d.date_deal > (NOW() - INTERVAL 24 MONTH) )";
	loopRows("Customers which their last purchase was 2 year ago or before:", query);

}


void MySQL::booksInInventoryByMonth()	// 20
{
	int month, year;

	// month
	std::cout << RESET << "Month (example -> 5): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2018): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	system("CLS");

	std::string date_in, date_out;

	if (month == 12)
		date_in = std::to_string(year + 1) + '-' + std::to_string(month - 11) + "-01";
	else
		date_in = std::to_string(year) + '-' + std::to_string(month + 1) + "-01";

	date_out = std::to_string(year) + '-' + std::to_string(month) + "-01";
	
	std::string query = "SELECT COUNT(*) FROM inventory WHERE location = 'storage' "
		"AND date_in < '" + date_in + "' AND(date_out >= '" + date_out +  "' OR date_out IS NULL)";
	

	loopRows("In " + std::to_string(month) + '/' + std::to_string(year) + ", There was ", query, " books that went through the inventory at some point");
}


void MySQL::notedButDidntPurchase()		// 21
{
	std::string query = "SELECT c.first_name, c.last_name FROM orders o "
		"INNER JOIN customer c ON c.customer_id = o.customer_id "
		"WHERE o.order_status = 'CUSTOMER NOTED' AND o.date_chg_st < (NOW() - INTERVAL 14 DAY);";
	loopRows("Customers who noted at the past 14 days about their order, but haven't baught yet:", query);

}


void MySQL::purchasesOfStoreBetDates()	// 22
{
	std::string date_start = getDate("FIRST");
	std::string date_end = getDate("SECOND");
	std::string query = "SELECT SUM(cost), COUNT(*) as total_books "
		"FROM inventory WHERE date_in > '" + date_start + "' AND date_in < '" + date_end + "'";
	loopRows("Total costs & amount of books between " + date_start + " and " + date_end, query);
}


void MySQL::totalProfitByMonth()		// 23
{
	int month, year;

	// month
	std::cout << RESET << "Month (example -> 3): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2019): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	system("CLS");

	std::string date_month_start, date_month_end;
	date_month_start = std::to_string(year) + '-' + std::to_string(month) + "-01";
	if (month == 12)
		date_month_end = std::to_string(year + 1) + '-' + std::to_string(month - 11) + "-01";
	else
		date_month_end = std::to_string(year) + '-' + std::to_string(month + 1) + "-01";

	std::string query = "SELECT ((SELECT SUM(total_price) FROM deal WHERE date_deal >= '"
		+ date_month_start + "' AND date_deal < '" + date_month_end + "') - SUM(cost)) AS profit "
		"FROM inventory WHERE date_in >= '" + date_month_start + "' AND date_in < '" + date_month_end + "'";
	loopRows("The store has made a total of ", query, " profit, in "  + std::to_string(month) + '/' + std::to_string(year));
}


void MySQL::totalDealsAvgByMonth()		// 24
{
	int year;
	std::cout << RESET << "Year (example -> 2019): " << CYAN;
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	std::string query = "SELECT AVG(total) FROM(SELECT SUM(total_price) AS total FROM deal WHERE YEAR(date_deal) = "
		+ std::to_string(year) + " GROUP BY MONTH(date_deal)) AS t";
	system("CLS");
	loopRows("On average, the sum of income from deals per month in " + std::to_string(year) + " is:", query);
}



void MySQL::empSalaryByMonth()			// 25
{
	std::string query = "SELECT w.total_hours * e.wage as emp_brutto FROM employee e "
		"INNER JOIN working_hours w ON e.emp_id = w.emp_id WHERE ";
	cout << RESET << "Employee First Name (example -> Moshe):" << CYAN << flush << endl;
	std::string first_name = getParam();
	cout << RESET << "Customer Last Name (example -> Kapulsky):" << CYAN << flush << endl;
	std::string last_name = getParam();
	query += ("e.first_name = " + first_name) + (" AND ") + ("e.last_name = " + last_name);

	int month, year;

	// month
	std::cout << RESET << "Month (example -> 1): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2019): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	system("CLS");

	query += " AND MONTH(w.date_m) =" + std::to_string(month);
	query += " AND YEAR(w.date_m) = " + std::to_string(year);

	
	loopRows("Brutto salary:", query);
}


void MySQL::topSellingEmpByMonth()
{
	int month, year;

	// month
	std::cout << RESET << "Month (example -> 7): " << CYAN;
	for (std::cin >> month; month < 1 || month > 12; std::cin >> month)
		std::cout << RED << "Month Can't Be " << month << "!, Try Again:" << CYAN << endl;

	// year
	std::cout << RESET << "Year (example -> 2020): " << CYAN;
	std::cin.ignore();
	for (cin >> year; year < 1990 || year > 2020; std::cin >> year)
		std::cout << RED << "Year Can't Be " << year << "!, Try Again: " << CYAN << endl;

	system("CLS");

	std::string query = "SELECT e.first_name, e.last_name, COUNT(*) as total_sales "
		"FROM deal d INNER JOIN employee e ON e.emp_id = d.emp_id WHERE MONTH(d.date_deal) = "
		+ std::to_string(month) + " AND YEAR(d.date_deal) = " + std::to_string(year) + 
		" GROUP BY(e.emp_id) ORDER by total_sales DESC LIMIT 1";

	loopRows("The top selling employee in " + std::to_string(month) + '/' + std::to_string(year)
		+ " is: ", query);
}


//------------------DESTRUCTOR--------------------//

MySQL :: ~MySQL()
{
    mysql_close (connect);
	std::cout << "\nclosing MySQL Connection... ";
	Sleep(1 * 1000);
}
