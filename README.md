# Aid-Management-Application
an application that manages the list of goods that need to be shipped to an disaster area. 

Aid Management Application (AMA)

Version 3.4.2

When disaster hits a populated area, the most critical task is to provide immediately affected people with what they need as quickly and as efficiently as possible.
This project creates an application that manages the list of goods that need to be shipped to ae disaster area. The application tracks the quantity of items needed, tracks the quantity on hand, and stores the information in a file for future use. 
There are two categories for the types of goods that need to be shipped: 
•	Non-Perishable goods, such as blankets and tents, which have no expiry date. We refer to goods in this category as Good objects.
•	Perishable goods, such as food and medicine, that have an expiry date. We refer to goods in this category as Perishable objects. 
To complete this project you will need to create several classes that encapsulate your solution. 

OVERVIEW OF THE CLASSES TO BE DEVELOPED

The classes used by the application are:
Date	
A class that holds the expiry date of the perishable items.
Error	
A class that tracks the error state of its client. Errors may occur during data entry and user interaction.
Good	
A class that manages a non-perishable good object.
Perishable	
A class that manages a perishable good object. This class inherits the structure of the “Good” class and manages a date.
iGood	
An interface to the Good hierarchy. This interface exposes the features of the hierarchy available to the application. Any “iGood” class can
•	read itself from the console or write itself to the console
•	save itself to a text file or load itself from a text file
•	compare itself to a unique C-style string identifier
•	determine if it is greater than another good in the collating sequence  
•	report the total cost of the items on hand
•	describe itself
•	update the quantity of the items on hand
•	report its quantity of the items on hand
•	report the quantity of items needed
•	accept a number of items
Using this class, the client application can 
•	save its set of iGoods to a file and retrieve that set at a later time
•	read individual item specifications from the keyboard and display them on the screen
•	update information regarding the number of each good on hand 

THE CLIENT APPLICATION

The client application manages the iGoods and provides the user with options to 
•	list the Goods
•	display details of a Good
•	add a Good
•	add items of a Good
•	update the items of a Good
•	delete a Good
•	sort the set of Goods

 
PROJECT CLASS DIAGRAM

 



 

