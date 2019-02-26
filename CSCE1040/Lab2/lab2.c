/* ***************************
Name:       Jason Powell
Course:     CSE 1040.00X
Lab:        CSE 1040.30X
Assignment: Lab 2
Due Date:   09/17/2013
*************************** */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int 	a = 0,          // index for stock data arrays
				market[150];    // market capitalization
	char 	symbol[150][6], // stock symbol
			 	command[2];     // process command
	float high[150],      // stock high value 
				low[150],       // stock low value
				close[150],     // closing price
				chng[150],      // change in value
				pct[150];       // change in value as percent

  // NOTE: you could have also done this without the arrays for the 
  //       stock market data.

	printf("123456789012345678901234567890123456789012345678901234567890\n");
  printf("  CODE     MID   CLOSE C   CHANGE PERCENT MID-DIFF  MKT CAP\n");
	while(scanf("%s", command) != EOF) {
		if(command[0] == 'p') {
			scanf("%s", symbol[a]);
			scanf("%f%f%f%d%f%f", &high[a], &low[a], &close[a], &market[a], 
            &chng[a], &pct[a]);
			printf("%6s%8.2f%8.2f + $%7.2f%7.2f%%%9.2f%9d\n", symbol[a], 
						 (high[a]+low[a])/2.0, close[a], chng[a], pct[a], 
						 (high[a]-low[a])/2.0-chng[a], market[a]);
		}
		else if(command[0] == 'n') {
		  scanf("%s", symbol[a]);
			scanf("%f%f%f%d%f%f", &high[a], &low[a], &close[a], &market[a], 
						&chng[a], &pct[a]);
      printf("%6s%8.2f%8.2f - $%7.2f%7.2f%%%9.2f%9d\n", symbol[a], 
             (high[a]+low[a])/2.0, close[a], chng[a], pct[a], 
             (high[a]-low[a])/2.0-chng[a], market[a]);
		}
		else { // command[0] == 's'
			scanf("%s", symbol[a]);
      scanf("%f%f%f%d", &high[a], &low[a], &close[a], &market[a]); 
			chng[a] = 0.0;
			pct[a] = 0.0;
      printf("%6s%8.2f%8.2f x $%7.2f%7.2f%%%9.2f%9d\n", symbol[a], 
             (high[a]+low[a])/2.0, close[a], chng[a], pct[a], 
             (high[a]-low[a])/2.0-chng[a], market[a]);
		}
		a++;
	}

	return 0;
}
