#include <minunit.h>
#include <bstrlib.h>


/* functions to test
 * bfromstr		Create a bstring from C style constant.
 * blk2bstr		Do the same thing, but give the length of the buffer.
 * bstrcpy		Copy a bstring.
 * bassign		Set on bstring to another.
 * bassignstr		Set a bstring to a C string's contents.
 * bassignblk		Set a bstring to a C string but give the length.
 * bdestroy		Destroy a bstring.
 * bconcat		Concatenate on bstring to another.
 * bstricmp		Compare two bstrings returning the same result as strcmp.
 * biseq		Test if two bstrings are equal.
 * binstr		Tell if one bstring is in another.
 * bfindreplace		Find one bstring in another, then replace it with a third.
 * bsplit		Split a bstring into a bstrList.
 * bformat		Do a format string, which is super handy.
 * blength		Get the length of a bstring.
 * bdata		Get the data from a bstring.
 * bchar		Get a char from a bstring.
 * */

char * test_bfromstr()
{
	return NULL;
}

char * test_blk2bstr()
{
	return NULL;
}

char * test_bstrcpy()
{
	return NULL;
} 

char * test_bassign()
{
	return NULL;
}

char * test_bassignstr()
{
	return NULL;
}

char * test_bdestroy()
{
	return NULL;
}

char * test_bconcat()
{
	return NULL;
}

char * test_bstricmp()
{
	return NULL;
}

char * test_biseq()
{
	return NULL;
}

char * test_binstr()
{
	return NULL;
}

char * test_bfindreplace()
{
	return NULL;
}

char * test_bsplit()
{
	return NULL;
}

char * test_bformat()
{
	return NULL;
}

char * test_blength()
{
	return NULL;
}

char * test_bdata()
{
	return NULL;
}

char * test_bchar()
{
	return NULL;
}

char *all_tests()
{
	mu_suite_start();

//	mu_run_test(test_bfromstr);
//	mu_run_test(est_blk2bstr);
//	mu_run_test(har * test_bstrcpy);
//	mu_run_test(test_bassign)
//	mu_run_test(test_bassignstr);
//	mu_run_test(test_bdestroy);
//	mu_run_test(test_bconcat);
//	mu_run_test(test_bstricmp);
//	mu_run_test(test_biseq);
//	mu_run_test(test_binstr);
//	mu_run_test(test_bfindreplace);
//	mu_run_test(test_bsplit);
//	mu_run_test(test_bformat);
//	mu_run_test(test_blength);
//	mu_run_test(test_bdata);
//	mu_run_test(test_bchar);

	return NULL;
}

RUN_TESTS(all_tests);
