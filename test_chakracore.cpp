#define TEST_CHAKRACORE 1

#include <stdio.h>
#include "chakracore.h"

int __cdecl printstring(const char *str) {
	printf("%s", str);
	return 0;
}

int main() {
	chakracore_prepare(printstring);
	chakracore_eval("console.log(\"^1hai\");");
	chakracore_eval("console.log(1);");
	chakracore_eval("console.log(2);");
	chakracore_eval("console.log(3);");
	chakracore_eval("console.log(4);");
	chakracore_eval("console.log(5);");
	chakracore_eval("a = 1");
	chakracore_eval("b = 2");
	chakracore_eval("c = a + b");
	chakracore_eval("console.log(\"c is\", c)");


	const char *eval_repl =
		"eval_repl = function(code) {"\
		"	try {					 "\
		"		var ret = eval(code);"\
		"		console.log(ret)	 "\
		"	}						 "\
		"	catch (e) {				 "\
		"		console.log(e);		 "\
		"	}						 "\
		"};							 ";
	chakracore_eval(eval_repl);
	chakracore_eval("eval_repl(\"112233\");"); // test succces case
	chakracore_eval("eval_repl(\";:_-:;\");"); // test fail case

	getchar();
}
