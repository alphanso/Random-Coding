%:- include('fulladder.pl'). % remove the '% at the starting of the include to include and check the 3 bit palindrome
%:- include('palindrome_3bit.pl'). % remove the '% at the starting of the include to include and check the 3 bit parity

myAnd(0,0,0).
myAnd(0,1,0).
myAnd(1,0,0).
myAnd(1,1,1).

myOr(0,0,0).
myOr(0,1,1).
myOr(1,0,1).
myOr(1,1,1).

myNot(0,1).
myNot(1,0).

elementAt(0,[H|_],N) :- N is H,!.
elementAt(I,[_|T],N) :- I1 is I - 1,elementAt(I1,T,N),!.


verify(R,I,O):-input(R,X),elementAt(X,I,O),!.
verify(R,I,O):-terminal(G,2,R),gate(myNot,G),terminal(G,1,X),verify(X,I,O1),myNot(O1,O),!.
verify(R,I,O):-terminal(G,3,R),gate(myAnd,G),terminal(G,1,X),terminal(G,2,Y),verify(X,I,O1),verify(Y,I,O2),myAnd(O1,O2,O),!.
verify(R,I,O):-terminal(G,3,R),gate(myOr,G),terminal(G,1,X),terminal(G,2,Y),verify(X,I,O1),verify(Y,I,O2),myOr(O1,O2,O),!.

