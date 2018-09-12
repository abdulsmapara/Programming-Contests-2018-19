<h3>Rahul's Lucky ID Number</h3>

<p>
  Tags: Data Structures, Segment Tree
</p>
<p>
  <b>Problem Statement</b>:<br />
   Given N integers, perform two types of queries on them-(if 1-based indexing followed)<br />
   1.  Update p-th index to q.<br />
   2.  Find the number of integers that can be represented as 2<sup>x</sup>+2<sup>y</sup> (x &ne; y, x &ge; 0, y &ge; 0) in the range [p,q].<br />
    <b>Constraints</b>:<br />
0<=Rahul’s Guess(id number)<= (10^9+1) <br />

0 < T <= 2 <br />

<b>0 < N <= 10^5 <br />

0 < Q <= 10^5 <br /></b>

m is either 1 or 2 <br />

1 <= p <= N <br />

0 <= q <= (10^9+1) (if m is 1) <br />

1 <= q<= N (if m is 2) <br />
  <br />
  <b>Approach</b>:<br />
  A naive approach was to solve the question in O(N * Q) time.<br />
  Note that the question was a standard update,range-sum query question on segment tree but can be solved using other data structures like Binary Indexed Tree,etc. also. <br />
  Time complexity using any of the above two approaches is O(Q * log N).<br />
  The solution using Binary Indexed tree and segment tree is provided.<br />
  
</p>
