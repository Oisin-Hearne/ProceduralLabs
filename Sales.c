#include <stdio.h>
#include <string.h>

void main() {
	FILE* fp;

	char deptname[10];
	int sales, totalSales=0, numHardware=0, totalHardwareSales=0, numGrocery=0, totalGrocerySales=0, numDrapery=0, totalDraperySales=0;
	int maxHardware=0, maxGrocery=0, maxDrapery=0;
	float averageHardware, averageGrocery, averageDrapery;
	int numinputs;


	fp = fopen("DailySales.txt", "r");

	if (fp == NULL)
	{
		printf(" ! File could not be opened. Cannot continue.\n");
	}
	else
	{
		while (feof(fp) == 0) //While there is still content left in the file
		{
			numinputs = fscanf(fp, "%s %d", deptname, &sales); //Input from file
			if (numinputs > 0) //Numinputs is used to check to make sure a line isn't empty.
			{
				printf("\n[Read: %s %d]", deptname, sales);

				totalSales += sales;

				//Depending on whether or not the line is Hardware, Grocery or Drapery
				//increment the num variable, check for new maximum and add to total sales.
				if (strcmp(deptname, "Hardware") == 0)
				{
					totalHardwareSales += sales;
					numHardware++;

					if (maxHardware < sales)
						maxHardware = sales;
				}
				else if (strcmp(deptname, "Grocery") == 0)
				{
					totalGrocerySales += sales;
					numGrocery++;

					if (maxGrocery < sales)
						maxGrocery = sales;
				}
				else if (strcmp(deptname, "Drapery") == 0)
				{
					totalDraperySales += sales;
					numDrapery++;

					if (maxDrapery < sales)
						maxDrapery = sales;
				}
			}
		}

		//Calulate averages
		averageHardware = (float)totalHardwareSales / numHardware;
		averageDrapery = (float)totalDraperySales / numDrapery;
		averageGrocery = (float)totalGrocerySales / numGrocery;

		//Print all results
		printf("\n\n = Results = \n * Total sales: %d", totalSales);
		printf("\n * Average Hardware Sales: %.2f\n * Highest Hardware Sales: %d", averageHardware, maxHardware);
		printf("\n * Average Grocery Sales: %.2f\n * Highest Grocery Sales: %d", averageGrocery, maxGrocery);
		printf("\n * Average Drapery Sales: %.2f\n * Highest Drapery Sales: %d\n\n", averageDrapery, maxDrapery);

		fclose(fp);
	}
}
