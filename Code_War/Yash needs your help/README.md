<h3>Yash needs your help!</h3>
<p>
  Tags: Array, Search
</p>

<p>
<b>Problem Statement</b>:<br />
Given N integers in the range defined on P, find the number (after each no. is provided) with maximum frequency of occurrence. If there are one or more such numbers print the number with the least value.
  <br /><br />
<b>Constraints</b>: <br />1 <= T <= 10<br />1 <= N <= 10^6<br /> <b>-10^4 <= P<= 10^4</b>
<br /><br />
<b>Solution</b>:<br />
  <br />
  The idea was to maintain a frequency array and a max variable (say <i>maximum</i>), that stores the required answer per testcase.<br />
 Given an integer P as input, increment its frequency and compare it with the frequency of <i>maximum</i>.<br />
 Two cases arise that we need to consider<br />
 Case 1:&nbsp;&nbsp; frequency of P is more than <i>maximum</i>, so update the <i>maximum</i> to P.<br/>
 Case 2:&nbsp;&nbsp; frequency of P is equal to <i>maximum</i>. Now choose the minimum among the two and update the <i>maximum</i> if required.<br />
  Note that we need not consider the case when frequency of P &lt; freqency of <i>maximum</i>.<br />
  Print <i>maximum</i> and repeat for N inputs.<br />
  <b>Note</b>: To take care for negative values that P can take, we observe that P is constrained as P >= -10^4 so we store the frequency of integer P at index P + 10^4 so that the frequency of -10^4 will be stored at index 0, of (-10^4 + 1) will be stored at index 1 and so on.
</p>
<br />
The solution in C language is provided.
<br />
