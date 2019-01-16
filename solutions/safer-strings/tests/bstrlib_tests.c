#include "minunit.h"
#include <bstrlib.h>
#include <stdio.h>

/* functions to test
 * bfromcstr		Create a bstring from C style constant.
 * blk2bstr		Do the same thing, but give the length of the buffer.
 * bstrcpy		Copy a bstring.
 * bassign		Set on bstring to another.
 * bassigncstr		Set a bstring to a C string's contents.
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

int cmpstr(unsigned char * str1, unsigned char * str2) {
	return strcmp((const char *)str1, (const char *)str2);
}

char * test_bfromcstr()
{
	const char test_value[] = "Hello world";
	bstring test = bfromcstr(test_value);

	// checking bfromcstr is not NULL
	mu_assert(test != NULL, "bfromcstr: failed to create bstring");
	
	// Checking length and slen
	int length = strlen(test_value);
	mu_assert(test->slen == length, "bfromcstr, slen not equal to length of word provided");

	mu_assert(test->data[test->slen] == '\0', "bfromstr bstring is not terminted");

	mu_assert(strcmp(test_value, (const char *)test->data) == 0, "test_bfromcstr wrong value returned");
	
	return NULL;
}

char * test_blk2bstr()
{
	const char test_value[] = { 'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'};
	bstring test = blk2bstr(test_value, 11);

	mu_assert(test != NULL, "blk2bstr: failed to create bstring");

	// Checking length
	int length = 11;
	mu_assert(test->slen == length, "blk2str: slen not equl to length of word");

	int cmp = strcmp(test_value, (const char *)test->data);

	mu_assert(cmp == 0, "blk2bstr: strings don't match");
	return NULL;

}

char * test_bstrcpy()
{
	const char test_value[] = "Hello world";
	bstring b0 = bfromcstr(test_value);
	bstring b1 = bstrcpy(b0);

	mu_assert(b0->slen == b1->slen, "bstrcpy: lengths don't match");

	int cmp = cmpstr(b0->data, b1->data);
	mu_assert(cmp == 0, "bstrcpy: strings do not match");

	return NULL;
} 

char * test_bassign()
{
	// bassign (bstring b0, const bstring b1);
	const char test_value_0[] = "foo";
	const char test_value_1[] = "Hello world";

	bstring bstr_test_0 = bfromcstr(test_value_0);
	const bstring bstr_test_1 = bfromcstr(test_value_1);
	
	int return_value = bassign(bstr_test_0, bstr_test_1);

	mu_assert(return_value == 0, "bassign: Failed to assign, return value not 0");

	int cmp = cmpstr(bstr_test_0->data, bstr_test_1->data);
	mu_assert(cmp == 0, "bassign: strings do not match");

	return NULL;
}

char * test_bassigncstr()
{
	const char init_value[] = "Hello";
	const char expected_value[] = "Hello world.";

	bstring init_bstring = bfromcstr(init_value);
	
	mu_assert(init_bstring != NULL, "bassingcstr: failed to initalise bstring");

	int cmp_init = strcmp((const char *)init_bstring->data, init_value);
	mu_assert(cmp_init == 0, "bassingcstr: failed to set initial bstring data");
	
	bassigncstr(init_bstring, expected_value);

	int cmp_expected = strcmp((const char *)init_bstring->data, expected_value);
	mu_assert(cmp_expected == 0, "bassigncstr: failed to assign bstring data");

	return NULL;
}

char * test_bdestroy()
{
	const char test_value[] = "Hello world";
	bstring test_bstring = bfromcstr(test_value);

	mu_assert(test_bstring != NULL, "bdestroy: bfromcstr: failed to create bstring");

	int result = bdestroy(test_bstring);

	mu_assert(result == BSTR_OK, "bdestroy: failed to destroy returned non zero value");

	// can not test free()
	//mu_assert(test_bstring == NULL, "bdestroy: bstring should be null");

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

	mu_run_test(test_bfromcstr);
	mu_run_test(test_blk2bstr);
	mu_run_test(test_bstrcpy);
	mu_run_test(test_bassign)
	mu_run_test(test_bassigncstr);
	mu_run_test(test_bdestroy);
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
