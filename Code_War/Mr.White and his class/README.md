<b>Mr.White and his class</b><br />
The question asked to solve the relation <br />
f(x) = f(x-1) + f(x+1)<br />
Solution<br />
f(x+1) = f(x) - f(x-1) <br />
Let x=2 and f(1)=a and f(2)=b be given<br />
f(3) = f(2) - f(1) = b-a<br />
f(4) = f(3) - f(2) = f(2) - f(1) - f(2) = -f(1) = -a<br />
f(5) = f(4) - f(3) = -f(1) - (b-a) = -b <br />
f(6) = f(5) - f(4) = -b + a <br />
f(7) = f(6) - f(5) = -b + a - (-b) = a = f(1) = f(1+6)<br />
If you perform for 8,9 and so on you realize that f(x+6) = f(x) and hence we can calculate the answer just by performing a modulo operation with 6.<br />
For taking modulo with 10^9+7 and dealing with modulo, take a look at the solution provided.
