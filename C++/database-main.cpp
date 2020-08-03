#include <windows.h>
#include "database.h"
   

void Clear()
{
#if defined _WIN32
	system("cls");
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
#elif defined (__APPLE__)
	system("clear");
#endif
}


bool startSwitch(MySQL &Store, int choice)
{
	switch (choice)
	{
	case (1):
	{
		Store.bookInInventory();
		break;
	}
	case (2):
	{
		Store.oldestCustomer();
		break;
	}
	case (3):
	{
		Store.oldestBookInStock();
		break;
	}
	case (4):
	{
		Store.showOrders();
		break;
	}
	case (5):
	{
		Store.bookPurchases();
		break;
	}
	case (6):
	{
		Store.mostReadedAuthorByDates();
		break;
	}
	case (7):
	{
		Store.topThreeBuyers();
		break;
	}
	case (8):
	{
		Store.mostTranslations();
		break;
	}
	case (9):
	{
		Store.customerPurchaseHistory();
		break;
	}
	case (10):
	{
		Store.customerOrderHistory();
		break;
	}
	case (11):
	{
		Store.calculateShipping();
		break;
	}
	case (12):
	{
		Store.splittedDeliveries();
		break;
	}
	case (13):
	{
		Store.deliveryStatus();
		break;
	}
	case (14):
	{
		Store.totalByXpress();
		break;
	}
	case (15):
	{
		Store.incomeFromBit();
		break;
	}
	case (16):
	{
		Store.aboveAvgDeals();
		break;
	}
	case (17):
	{
		Store.israelPostAndXpress();
		break;
	}
	case (18):
	{
		Store.diffEditionSameDelivery();
		break;
	}
	case (19):
	{
		Store.notReturningCustomers();
		break;
	}
	case (20):
	{
		Store.notedButDidntPurchase();
		break;
	}
	case (21):
	{
		Store.booksInInventoryByMonth();
		break;
	}
	case (22):
	{
		Store.purchasesOfStoreBetDates();
		break;
	}
	case (23):
	{
		Store.totalProfitByMonth();
		break;
	}
	case (24):
	{
		Store.totalDealsAvgByMonth();
		break;
	}
	case (25):
	{
		Store.empSalaryByMonth();
		break;
	}
	case (26):
	{
		Store.topSellingEmpByMonth();
		break;
	}


	case (0):
	{
		std::cout << "Thank you for using our Book-Store system!\n";
		Sleep(2 * 1000);
		return FALSE;
	}

	default:
		std::cout << "CHOICE ERROR!...";
		Sleep(0.5 * 1000);
		std::cout << " Try again" << endl;
	}
	Sleep(1 * 1000);
	return TRUE;
}



int main(void)
{
	MySQL Store;
	std::cout << "\nWelcome to David & Omri Book Shop :)" << endl;
	Sleep(3 * 1000);
	int choice = 0;
	Clear();
	while (true)
	{
		std::cout << YELLOW << "\nMAIN MENU:\n" << RESET << std::endl;
		std::cout << "1.  Check if a book is in stock\t\t\t14. Sum of deliveries by Xpress" << endl;
		std::cout << "2.  Which customer is our oldest customer\t15. Total income in \"Bit\" " << endl;
		std::cout << "3.  Which book is the oldest in store?\t\t16. Above average deals in the past 12 months " << endl;
		std::cout << "4.  Current Orders list\t\t\t\t17. Total Israel Post & Xpress deliveries in the past 12 months" << endl;
		std::cout << "5.  How many times a book has been sold?\t18. Deliveries which had different edition of same book" << endl;
		std::cout << "6.  Most readed author between dates\t\t19. Customers which their last purchase was 2 year ago(or before)" << endl;
		std::cout << "7.  Stores Top 3 buying customers\t\t20. Customers who noted about their Order but never came to buy" << endl;
		std::cout << "8.  Maximum in-stock Translated Book\t\t21. Books in inventory - by month" << endl;
		std::cout << "9.  Customer's Purchase history \t\t22. Books purchased by the store between dates" << endl;
		std::cout << "10. Customer's Orders history\t\t\t23. Profit by Month" << endl;
		std::cout << "11. Shipping cost for a book(s) package\t\t24. Yearly deals average by month" << endl;
		std::cout << "12. Splitted deliveries by a customer\t\t25. Employee salary calculation" << endl;
		std::cout << "13. Specific delivery Status\t\t\t26. Best seller (employee) by month" <<endl ;
		std::cout << RED << "\n0. EXIT\n" << CYAN << endl;
		std::cin >> choice;

		Clear();
		std::cout << YELLOW << choice << ')' << RESET << endl;
		std::cin.ignore();
		try
		{
			if (!startSwitch(Store, choice))
				return 0;
		}
		catch (const char* err)
		{
			cout << RED << err << RESET << endl;
			Sleep(1000 * 1);
		}
	}
}
