-- MySQL dump 10.13  Distrib 8.0.19, for Win64 (x86_64)
--
-- Host: localhost    Database: book_store
-- ------------------------------------------------------
-- Server version	8.0.19

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `author`
--

DROP TABLE IF EXISTS `author`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `author` (
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(30) DEFAULT NULL,
  `book_id` smallint unsigned NOT NULL,
  KEY `book_id` (`book_id`),
  CONSTRAINT `author_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `author`
--

LOCK TABLES `author` WRITE;
/*!40000 ALTER TABLE `author` DISABLE KEYS */;
INSERT INTO `author` VALUES ('David','Tsibulsky',2),('Yossi','Aziz',3),('Yonni','Vasovsky',3),('Abram','Ruzvelt',4),('Moyshe','Mendelevsky',5),('Ramzaz','Azurbaev',6),('Asuska','Mazuslkin',1),('Leonid','Asupov',7),('Lola','Abrimova',8),('Alona','Kabelskaya',9),('Danit','Rubbin',10),('Asuska','Mazuslkin',11),('Asuska','Mazuslkin',12),('Tal','Musseri',13),('Muki','Unknown',14),('Noa','Kirel',15),('Ari','Gold',16),('Vladi','Karatsuba',17),('Vladi','Karatsuba',18);
/*!40000 ALTER TABLE `author` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `book`
--

DROP TABLE IF EXISTS `book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `book` (
  `book_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `title` varchar(30) NOT NULL,
  `weight` float DEFAULT NULL,
  `lang` varchar(20) DEFAULT NULL,
  `pages` smallint unsigned DEFAULT NULL,
  `publisher` varchar(25) DEFAULT NULL,
  `publish_year` smallint unsigned DEFAULT NULL,
  `translator` varchar(30) DEFAULT NULL,
  PRIMARY KEY (`book_id`)
) ENGINE=InnoDB AUTO_INCREMENT=19 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `book`
--

LOCK TABLES `book` WRITE;
/*!40000 ALTER TABLE `book` DISABLE KEYS */;
INSERT INTO `book` VALUES (1,'Harry Potter',1.8,'english',625,'or_ha_teva',2001,'Mosh Dayar'),(2,'Web (Beginners)',2.1,'english',325,'hagada-laOr',1979,NULL),(3,'armagedon2',3.1,'spanish',515,'or_ha_teva',1999,'Abus Kadan'),(4,'die hard3',2.2,'russian',317,'hagada-laOr',2002,'Shimon Dron'),(5,'Osiimons',3,'russian',441,'putnic',1997,'Astrib Amussi'),(6,'Karribs',1.1,'portuguese',187,'suevet',1977,NULL),(7,'some love story',1.9,'hebrew',275,'addon-or',1969,NULL),(8,'pontiac',2.75,'english',377,'hotz-besed',2003,NULL),(9,'terminator',3.09,'hebrew',412,'baba-or',1972,NULL),(10,'calculus',2.31,'german',334,'or_ha_karav',2005,'Toma Timberlen'),(11,'Harry Potter',2.5,'Chinese',625,'Ching_books',2001,'Nang Yuan'),(12,'Harry Potter',2.4,'Chinese',620,'KYOTO',2002,'Yao Ming'),(13,'Ugi Ve HaMakakim',0.7,'English',120,'Kids_publish',1999,NULL),(14,'Mekofef Habananot',0.4,'Hebrew',29,'Shabaq S',2002,NULL),(15,'Million Dollar',2.19,'Hebrew',12,'Noa Killa inc.',2020,NULL),(16,'Joshua Tree Afternoon',1.2,'English',400,'Entourage inc.',2004,NULL),(17,'Karatsuba Algorithm',1.5,'Russian',395,'Russia-math',1977,NULL),(18,'Karatsuba Algorithm',1.2,'English',310,'Math Books inc.',1978,'David Tsibulsky');
/*!40000 ALTER TABLE `book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `customer`
--

DROP TABLE IF EXISTS `customer`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `customer` (
  `customer_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `first_name` varchar(30) DEFAULT NULL,
  `last_name` varchar(30) DEFAULT NULL,
  `mobile` int unsigned DEFAULT NULL,
  `landline` int unsigned DEFAULT NULL,
  `date_join` date DEFAULT NULL,
  PRIMARY KEY (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `customer`
--

LOCK TABLES `customer` WRITE;
/*!40000 ALTER TABLE `customer` DISABLE KEYS */;
INSERT INTO `customer` VALUES (1,'Moshe','Reuveny',549321253,23451234,'2015-01-10'),(2,'Shmulik','Zarugal',549124453,33451234,'2016-02-12'),(3,'Itzhak','Aznary',529328439,83452134,'2016-10-15'),(4,'Garrik','Mozes',549321253,23451234,'2015-01-10'),(5,'Itshak','Nudler',501325783,23451231,'2020-07-28'),(6,'Avivit','Levy',549321237,32451123,'2011-02-06'),(7,'Ronni','Feldman',520921253,30451209,'2013-02-13'),(8,'Yonatan','Alfassy',587231311,33410092,'2018-09-22'),(9,'Habib','Ahmaedov',571192283,33422131,'2011-02-11'),(10,'Nira','Zandubi',512321198,41234321,'2015-04-09');
/*!40000 ALTER TABLE `customer` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `deal`
--

DROP TABLE IF EXISTS `deal`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `deal` (
  `deal_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `date_deal` date DEFAULT NULL,
  `total_price` float DEFAULT NULL,
  `deal_type` varchar(10) DEFAULT NULL,
  `payment_type` varchar(20) DEFAULT NULL,
  `customer_id` smallint unsigned NOT NULL,
  `emp_id` int unsigned NOT NULL,
  PRIMARY KEY (`deal_id`),
  KEY `customer_id` (`customer_id`),
  KEY `emp_id` (`emp_id`),
  CONSTRAINT `deal_ibfk_1` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`),
  CONSTRAINT `deal_ibfk_2` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`)
) ENGINE=InnoDB AUTO_INCREMENT=13 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `deal`
--

LOCK TABLES `deal` WRITE;
/*!40000 ALTER TABLE `deal` DISABLE KEYS */;
INSERT INTO `deal` VALUES (1,'2015-01-10',39.9,'Delivery','Credit Card',1,378912198),(2,'2016-02-12',79.9,'Delivery','Bit',2,378912198),(3,'2016-10-15',112.1,'Delivery','Bit',3,29873123),(4,'2019-05-22',61.9,'Delivery','Credit Card',4,378912198),(5,'2019-11-12',71.9,'Delivery','Credit Card',5,19222193),(6,'2019-02-11',13.1,'Delivery','Credit Card',4,378912198),(7,'2019-03-31',172.1,'In-store','Bit',3,19222193),(8,'2018-06-05',103.4,'In-store','Bank transfer',7,378912198),(9,'2018-01-03',111.1,'In-store','Cash',8,19222193),(10,'2018-09-02',55.44,'In-store','Credit Card',9,19222193),(11,'2020-01-09',50.9,'In-store','Cash',6,378912198),(12,'2020-07-30',187.6,'Delivery','Credit Card',10,29873123);
/*!40000 ALTER TABLE `deal` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `delivery`
--

DROP TABLE IF EXISTS `delivery`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `delivery` (
  `del_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `address` varchar(40) DEFAULT NULL,
  `del_status` varchar(35) DEFAULT NULL,
  `price` float NOT NULL,
  `tracking_num` varchar(20) NOT NULL,
  `method_id` smallint unsigned NOT NULL,
  `deal_id` smallint unsigned NOT NULL,
  PRIMARY KEY (`del_id`),
  KEY `method_id` (`method_id`),
  KEY `deal_id` (`deal_id`),
  CONSTRAINT `delivery_ibfk_1` FOREIGN KEY (`method_id`) REFERENCES `shipping_method` (`method_id`),
  CONSTRAINT `delivery_ibfk_2` FOREIGN KEY (`deal_id`) REFERENCES `deal` (`deal_id`)
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `delivery`
--

LOCK TABLES `delivery` WRITE;
/*!40000 ALTER TABLE `delivery` DISABLE KEYS */;
INSERT INTO `delivery` VALUES (1,'Israel Haifa Hadar 40/1','(3) COLLECTION',24.28,'Ep23113234rt',4,4),(2,'Israel Jerusalem Koresh 26/4','(4) HANDED',12.88,'Ep987236354lk',3,5),(3,'Israel Jerusalem Haor 15/5','(2) SENT',13.14,'Es124556687ew',2,3),(4,'Israel Tel Aviv Valensia 32/12','(1) PREPARATION',15.21,'',5,6),(5,'Israel Jerusalem Givat Shaul 28/13','(3) COLLECTION',40.14,'Es6192123487ka',4,1),(6,'Israel Tel Aviv Arlazorov 12/3','(1) PREPARATION',66.11,'',1,1),(7,'Israel Tel Aviv Kohvey-Itzhak 54/3','(4) HANDED',13.12,'Es6866982743r1',3,2),(8,'Israel Tel Aviv Pinhas 21/15','(2) SENT',25.12,'Ew2866712334ka',5,2),(9,'Israel Jerusalem Dov-Yossef 43/13','(1) PREPARATION',16.18,'',1,5),(10,'Israel Jerusalem Nof-harim 72/15','(2) SENT',23.77,'Yc209098587lk',2,6),(11,'Israel Shoham Tavor 86','(4) HANDED',37.53,'ES254692716IL',1,12);
/*!40000 ALTER TABLE `delivery` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `delivery_book`
--

DROP TABLE IF EXISTS `delivery_book`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `delivery_book` (
  `book_id` smallint unsigned NOT NULL,
  `del_id` smallint unsigned NOT NULL,
  KEY `delivery_book_ibfk_3` (`del_id`),
  KEY `book_id` (`book_id`),
  CONSTRAINT `delivery_book_ibfk_3` FOREIGN KEY (`del_id`) REFERENCES `delivery` (`del_id`),
  CONSTRAINT `delivery_book_ibfk_4` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `delivery_book`
--

LOCK TABLES `delivery_book` WRITE;
/*!40000 ALTER TABLE `delivery_book` DISABLE KEYS */;
INSERT INTO `delivery_book` VALUES (1,6),(2,6),(3,7),(5,7),(6,8),(10,3),(4,1),(3,9),(1,2),(2,10),(17,11),(18,11);
/*!40000 ALTER TABLE `delivery_book` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `employee`
--

DROP TABLE IF EXISTS `employee`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `employee` (
  `emp_id` int unsigned NOT NULL,
  `first_name` varchar(30) NOT NULL,
  `last_name` varchar(30) DEFAULT NULL,
  `phone` int unsigned DEFAULT NULL,
  `address` varchar(40) DEFAULT NULL,
  `password` smallint unsigned NOT NULL,
  `is_manager` tinyint(1) DEFAULT NULL,
  `date_start` date DEFAULT NULL,
  `date_end` date DEFAULT NULL,
  `wage` float DEFAULT NULL,
  PRIMARY KEY (`emp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `employee`
--

LOCK TABLES `employee` WRITE;
/*!40000 ALTER TABLE `employee` DISABLE KEYS */;
INSERT INTO `employee` VALUES (19222193,'Anna','Pakinshtein',532468876,'Bat-Yam Hertzel 52/6',1389,0,'2017-03-12','2020-01-10',32),(29234821,'Lolita','Maldovsky',522345432,'Holon Dov-oz 121/11',1785,0,'2016-03-13','2020-07-21',34),(29873123,'Moshe','Kapulsky',538746589,'Tel Aviv Arlozorov 16/2',1125,1,'2011-01-12',NULL,60),(127109832,'Aron','Lunerberg',507888677,'Bat-Yam Kdushey-Kahir 12/4',7971,0,'2013-01-14','2015-06-11',34.5),(198121133,'Ahmed','Ararr',557621311,'Ramat-Gan jabotinsky 118/1',1365,0,'2016-03-13',NULL,33),(211234321,'Yossi','Suker',521345676,'Tel-Aviv Kakal 115/12',1363,0,'2012-09-19','2013-08-28',34),(218874433,'Rima','Pakalevsky',537566543,'Tel-Aviv Bney-Efraim 15/1',7621,0,'2017-04-01',NULL,37),(302121154,'Haim','Kohen',532214322,'Holon Eylat 35/2',1567,0,'2013-03-31','2017-12-31',33.5),(302123412,'Andrey','Aroni',521231111,'Bat-Yam Yoseftal 11/1',6725,0,'2017-03-18','2019-06-22',34.5),(309211123,'Fima','Lugalko',509871231,'Bat-Yam  katzenelson 12/3',1222,0,'2019-11-03',NULL,35),(378912198,'David','Luner',553278192,'Bat-Yam daniel 32/16',1325,0,'2015-02-22',NULL,32.5);
/*!40000 ALTER TABLE `employee` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `expenses`
--

DROP TABLE IF EXISTS `expenses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `expenses` (
  `date_ex` date NOT NULL,
  `rent` smallint unsigned DEFAULT NULL,
  `salaries` double DEFAULT NULL,
  `phone_bill` float DEFAULT NULL,
  `landline_bill` float DEFAULT NULL,
  `electricity` float DEFAULT NULL,
  `water` float DEFAULT NULL,
  `prop_tax` float DEFAULT NULL,
  `il_post` float DEFAULT NULL,
  `xpress` float DEFAULT NULL,
  PRIMARY KEY (`date_ex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `expenses`
--

LOCK TABLES `expenses` WRITE;
/*!40000 ALTER TABLE `expenses` DISABLE KEYS */;
INSERT INTO `expenses` VALUES ('2019-01-00',1230,15320.2,230,123,430.1,230.3,127.21,231.12,17.23),('2019-02-00',1230,18120.21,231.01,112.32,421.12,245.11,128.8,212.11,36.82),('2019-03-00',1230,11234.11,280.08,123.43,451.1,211.14,128.86,241.12,56.63),('2019-04-00',1230,15674.23,212.2,127.3,512.11,243.35,126.62,221.12,112.32),('2019-05-00',1230,18763.5,214.3,113.13,510.13,243.33,132.21,232.12,65.45),('2019-06-00',1470,16543.23,211.2,112.01,470.15,233.35,134.23,233.12,12.01),('2019-07-00',1470,19834.23,242.4,124.02,454.55,234.32,132.11,243.13,123.12),('2019-08-00',1470,12134.24,223.02,124.34,443.12,224.56,132.56,224.13,13.03),('2019-09-00',1550,14123.24,253.43,164.46,446.14,265.53,137.25,289.82,88.99),('2019-10-00',1550,1660.18,243.56,133.3,398.04,245.68,122.7,199.96,17.97);
/*!40000 ALTER TABLE `expenses` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `inventory`
--

DROP TABLE IF EXISTS `inventory`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `inventory` (
  `inv_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `price` float DEFAULT NULL,
  `cost` float DEFAULT NULL,
  `book_condition` varchar(20) DEFAULT NULL,
  `location` varchar(15) DEFAULT NULL,
  `date_in` date DEFAULT NULL,
  `date_out` date DEFAULT NULL,
  `book_id` smallint unsigned NOT NULL,
  `deal_id` smallint unsigned DEFAULT NULL,
  PRIMARY KEY (`inv_id`),
  KEY `book_id` (`book_id`),
  KEY `deal_id` (`deal_id`),
  CONSTRAINT `inventory_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`),
  CONSTRAINT `inventory_ibfk_2` FOREIGN KEY (`deal_id`) REFERENCES `deal` (`deal_id`)
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `inventory`
--

LOCK TABLES `inventory` WRITE;
/*!40000 ALTER TABLE `inventory` DISABLE KEYS */;
INSERT INTO `inventory` VALUES (1,84.9,62,'new','storage','2018-05-21','2018-09-02',1,10),(2,70.9,64,'bad','store','2018-05-21','2018-01-03',2,9),(3,65.9,32,'new','store','2015-09-20','2018-06-05',3,8),(4,39.9,29,'like new','store','2018-05-21','2019-03-31',4,7),(5,29.9,12.31,'like new','storage','2018-05-21','2019-02-11',9,6),(6,79.9,35.1,'new','store','2014-05-16','2016-02-12',18,4),(7,52.9,21.1,'good','storage','2019-03-12',NULL,7,NULL),(8,65.9,30.21,'good','store','2012-05-21',NULL,8,3),(9,61.9,19.9,'medium','storage','2018-05-21',NULL,9,NULL),(10,29.9,12.31,'new','store','2011-05-11',NULL,9,8),(11,39.9,19.6,'new','store','2011-05-11','2015-01-10',15,1),(12,29.9,14.5,'like new','store','2011-05-11','2016-02-12',15,2),(13,71.9,40,'like new','store','2018-05-21','2019-11-12',17,5),(14,50.9,25,'new','store','2020-01-01','2020-01-09',16,11),(15,71.9,40,'new','store','2020-01-05','2020-07-30',17,12),(16,79.9,35.1,'new','store','2020-01-05','2020-07-30',18,12);
/*!40000 ALTER TABLE `inventory` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `orders`
--

DROP TABLE IF EXISTS `orders`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `orders` (
  `order_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `date_order` date NOT NULL,
  `book_id` smallint unsigned NOT NULL,
  `customer_id` smallint unsigned DEFAULT NULL,
  `order_status` varchar(16) DEFAULT NULL,
  `date_chg_st` date DEFAULT NULL,
  PRIMARY KEY (`order_id`),
  KEY `book_id` (`book_id`),
  KEY `customer_id` (`customer_id`),
  CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`book_id`) REFERENCES `book` (`book_id`),
  CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`customer_id`) REFERENCES `customer` (`customer_id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `orders`
--

LOCK TABLES `orders` WRITE;
/*!40000 ALTER TABLE `orders` DISABLE KEYS */;
INSERT INTO `orders` VALUES (1,'2020-08-01',2,5,'IN STOCK','2020-08-03'),(2,'2019-12-11',3,3,'IN STOCK','2019-12-18'),(3,'2019-11-30',4,3,'CUSTOMER NOTED','2019-12-18'),(4,'2019-10-28',3,2,'CANCELED','2019-10-29'),(5,'2019-12-25',5,7,'CUSTOMER NOTED','2020-08-02'),(6,'2020-02-16',7,8,'BAUGHT','2020-02-19'),(7,'2019-09-13',5,6,'NOT IN STOCK','2019-09-13'),(8,'2020-01-12',4,7,'BAUGHT','2020-01-25'),(9,'2019-01-08',3,1,'NOT IN STOCK','2019-01-08'),(10,'2020-06-22',2,4,'NOT IN STOCK','2020-06-22');
/*!40000 ALTER TABLE `orders` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `shipping_method`
--

DROP TABLE IF EXISTS `shipping_method`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `shipping_method` (
  `method_id` smallint unsigned NOT NULL AUTO_INCREMENT,
  `method_name` varchar(15) DEFAULT NULL,
  `company` varchar(17) DEFAULT NULL,
  `kg_price` float DEFAULT NULL,
  PRIMARY KEY (`method_id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `shipping_method`
--

LOCK TABLES `shipping_method` WRITE;
/*!40000 ALTER TABLE `shipping_method` DISABLE KEYS */;
INSERT INTO `shipping_method` VALUES (1,'Courier Service','Israel Post',13.9),(2,'EMS Service','Israel Post',25.9),(3,'Registered','Israel Post',19.9),(4,'Collect Point','-Xpress-',29.5),(5,'Courier to Home','-Xpress-',35.9);
/*!40000 ALTER TABLE `shipping_method` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `working_hours`
--

DROP TABLE IF EXISTS `working_hours`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `working_hours` (
  `date_m` date NOT NULL,
  `total_hours` float DEFAULT NULL,
  `emp_id` int unsigned NOT NULL,
  KEY `emp_id` (`emp_id`),
  CONSTRAINT `working_hours_ibfk_1` FOREIGN KEY (`emp_id`) REFERENCES `employee` (`emp_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `working_hours`
--

LOCK TABLES `working_hours` WRITE;
/*!40000 ALTER TABLE `working_hours` DISABLE KEYS */;
INSERT INTO `working_hours` VALUES ('2019-01-01',125.3,378912198),('2019-02-01',143.3,378912198),('2019-01-01',128.19,29873123),('2019-02-01',110,29873123),('2020-01-01',111.12,29873123),('2019-01-01',134.24,29234821),('2019-02-01',115.15,29234821),('2019-03-01',116,29234821),('2019-01-01',156.3,19222193),('2019-03-01',118.2,198121133);
/*!40000 ALTER TABLE `working_hours` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2020-08-03 14:55:57
