# Accounting

## Original link

[Accounting on Kattis](https://open.kattis.com/problems/bokforing)

## Principle

### Description

Erika the economist studies economic inequality. Her model starts in a situation where everybody has the same amount of money. After that, people’s wealth changes in various complicated ways.

Erika needs to run a simulation a large number of times to check if her model works. The simulation consists of 𝑁 people, each of whom begins with 0 kroners. Then 𝑄 events happen, of three different types:

* An event of type “SET 𝑖 𝑥” means that the 𝑖th person’s wealth is set to 𝑥.
* An event of type “RESTART 𝑥” means that the simulation is restarted, and everybody’s wealth is set to 𝑥.  
* An event of type “PRINT 𝑖” reports the current wealth of the 𝑖th person.  

Unfortunately, Erika’s current implementation is very slow; it takes far too much time to keep track of how much money everybody has. She decides to use her algorithmic insights to speed up the simulation.

### Input

The first line includes two integers 𝑁 and 𝑄, where 1≤𝑁≤10^6 and 1≤𝑄≤2⋅10^5. The following 𝑄 lines each start with a string that is either “SET”, “RESTART”, or “PRINT. There is guaranteed to be at least one event of type “PRINT”.

If the string is “SET” then it is followed by two integers 𝑖 and 𝑥 with 1≤𝑖≤𝑁 and 0≤𝑥≤10^4. If the string is “RESTART” then it is followed by an integer 𝑥 with 0≤𝑥≤10^4. If the string is “PRINT” then it is followed by an integer 𝑖 with 1≤𝑖≤𝑁.

### Output

For each event of type “PRINT”, write the 𝑖th person’s capital.

<table>
<tr>
<td>Sample Input</td><td>Sample Output</td>
</tr>
<tr>
<td>

```
3 5
SET 1 7
PRINT 1
PRINT 2
RESTART 33
PRINT 1
```
</td>
<td>

```
7
0
33
```
</td>
</tr>
</tr>
<tr>
<td>

```
5 7
RESTART 5
SET 3 7
PRINT 1
PRINT 2
PRINT 3
PRINT 4
PRINT 5
```
</td>
<td>

```
5
5
7
5
5
```
</td>
</tr>
</table>