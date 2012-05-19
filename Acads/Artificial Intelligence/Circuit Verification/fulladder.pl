%relations of the gates with the terminals and input and output signals. 
% the circuit is defined for 3 bit parity .

gate(myNot,g1).
gate(myNot,g2).
gate(myAnd,g3).
gate(myAnd,g4).
gate(myOr,g5).
gate(myAnd,g8).
gate(myAnd,g9).
gate(myOr,g10).
gate(myNot,g11).
gate(myNot,g12).
gate(myAnd,g13).
gate(myAnd,g14).
gate(myOr,g15).

input(a,0).
input(b,1).
input(c,2).
%xor1  :- SUM
terminal(g1,1,a).
terminal(g1,2,i1).
terminal(g2,1,b).
terminal(g2,2,i2).
terminal(g3,1,i1).
terminal(g3,2,b).
terminal(g3,3,i3).
terminal(g4,1,a).
terminal(g4,2,i2).
terminal(g4,3,i4).
terminal(g5,1,i3).
terminal(g5,2,i4).
terminal(g5,3,i5).
%xor2
terminal(g11,1,i5).
terminal(g11,2,i11).
terminal(g12,1,c).
terminal(g12,2,i12).
terminal(g13,1,i11).
terminal(g13,2,c).
terminal(g13,3,i13).
terminal(g14,1,i5).
terminal(g14,2,i12).
terminal(g14,3,i14).
terminal(g15,1,i13).
terminal(g15,2,i14).
terminal(g15,3,parity).

%carry
terminal(g8,1,i5).
terminal(g8,2,c).
terminal(g8,3,i7).
terminal(g9,1,a).
terminal(g9,2,b).
terminal(g9,3,i6).
terminal(g10,1,i7).
terminal(g10,2,i6).
terminal(g10,3,carry).



