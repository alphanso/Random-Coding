%relations of the gates with the terminals and input and output signals. 
% the circuit is defined for 3 bit palindrome .
gate(myNot,g1).
gate(myNot,g2).
gate(myAnd,g3).
gate(myAnd,g4).
gate(myOr,g5).
gate(myNot,g6).

terminal(g1,1,in1).
terminal(g1,2,i1).
terminal(g2,1,in3).
terminal(g2,2,i2).
terminal(g3,1,i1).
terminal(g3,2,in3).
terminal(g3,3,i3).
terminal(g4,1,in1).
terminal(g4,2,i2).
terminal(g4,3,i4).
terminal(g5,1,i3).
terminal(g5,2,i4).
terminal(g5,3,i6).
terminal(g6,1,i6).
terminal(g6,2,palindrome).

input(in1,0).
input(in2,1).
input(in3,2).
