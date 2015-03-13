
/*
browserstack written : 
XML parse plus series computation
Evaluate an expression given in XML format. Keys will be Expr- contains the entire expression.
 Elem – contains the digit, sum, Prod- contains two or more keys whose evaluation needs
  to be summed or multiplied respectively. Sub will contain 2 keys or more, where the 
  second key onwards will have to be subtracted from the first one. Div- will contain
   2 keys in which first key will need to be divided by second.

SAMPLE INPUT:

<expr>
<sum>
<elem>4</elem>
<elem>6</elem>
<elem>7</elem>
<elem>3</elem>
</sum>
</expr>

*/
#include <iostream>
#include <string>
using namespace std;

int evaluate_sum(string str1[10000], int pos){
	if(str1[pos].equals("<sum>"))
		int ans = eval_sum()
}

int main(){
	string inp[1000];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	cin>>inp[i]; 		

	evaluate_exp(inp);
}