#include "header.h"
#include "database-detail.h"
#include <string>

#define RESET   "\033[0m"
#define RED     "\033[1m\033[31m"   
#define GREEN   "\033[1m\033[32m"    
#define YELLOW  "\033[1m\033[33m"    
#define BLUE    "\033[1m\033[34m"      
#define MAGENTA "\033[1m\033[35m"    
#define CYAN    "\033[1m\033[36m"  


class MySQL
{
    protected:
        MYSQL *connect;
        MYSQL_RES *res_set;
        MYSQL_ROW row;
        unsigned int i;
		
    public:
        MySQL();
		void ShowTables();							// Not in use
		std::string getParam();						// getting a parameter from user for query
		int askNameOrID();							// asking by ID or Name when looking for customer
		std::string getDate(std::string date_num);	// getting a date from user for query
		void loopRows(string result_title, string query, string after_result_str);	// printing query result
		

		//---------------------------- QUERIES ---------------------------//

		void bookInInventory();			// 1
		void oldestCustomer();			// 2
		void showOrders();				// 3
		void oldestBookInStock();		// 4
		void bookPurchases();			// 5
		void mostReadedAuthorByDates();	// 6
		void topThreeBuyers();			// 7
		void mostTranslations();		// 8
		void customerPurchaseHistory();	// 9
		void customerOrderHistory();	// 10
		void calculateShipping();		// 11
		void splittedDeliveries();		// 12
		void deliveryStatus();			// 13
		void totalByXpress();			// 14
		void incomeFromBit();			// 15
		void aboveAvgDeals();			// 16
		void israelPostAndXpress();		// 17
		void diffEditionSameDelivery();	// 18
		void notReturningCustomers();	// 19
		void notedButDidntPurchase();	// 20
		void booksInInventoryByMonth();	// 21
		void purchasesOfStoreBetDates();// 22
		void totalProfitByMonth();		// 23 
		void totalDealsAvgByMonth();	// 24 
		void empSalaryByMonth();		// 25
		void topSellingEmpByMonth();	// 26

        ~MySQL();
};
