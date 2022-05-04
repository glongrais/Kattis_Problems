# 3D Printed Statues

## Original link

[3D Printed Statues on Kattis](https://open.kattis.com/problems/3dprinter)

## Principle

### Description

You have a single 3D printer, and would like to use it to produce 𝑛 statues. However, printing the statues one by one on the 3D printer takes a long time, so it may be more time-efficient to first use the 3D printer to print a new printer. That new printer may then in turn be used to print statues or even more printers. Print jobs take a full day, and every day you can choose for each printer in your possession to have it print a statue, or to have it 3D print a new printer (which becomes available for use the next day).

What is the minimum possible number of days needed to print at least 𝑛 statues?

### Input

The input contains a single integer 𝑛 (1≤𝑛≤10000), the number of statues you need to print.

### Output

Output a single integer, the minimum number of days needed to print at least 𝑛 statues.

| Sample Input | Sample Output |  
| :---: | :---: |  
| ``` 1 ``` | ``` 1 ``` |
| ``` 5 ``` | ``` 4 ``` |
| ``` 10 ``` | ``` 5 ``` |
| ``` 1000 ``` | ``` 11 ``` |
