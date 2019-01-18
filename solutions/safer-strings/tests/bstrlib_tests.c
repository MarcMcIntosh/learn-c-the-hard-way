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
	const char test_string[] = "Hello";
	const char test_string_to_append[] = " world";
	const char expect[] = "Hello world";
	bstring test_bstring = bfromcstr(test_string);
	bstring append = bfromcstr(test_string_to_append);

	int result = bconcat(test_bstring, append);

	mu_assert(result == BSTR_OK, "bconcat: returned non zero value");

	int cmp = strcmp((const char*)test_bstring->data, expect);

	mu_assert(cmp == 0, "bconcat: data does not match expected result");

	return NULL;
}

char * test_bstricmp()
{
	bstring b0 = bfromcstr("Hello World");
	bstring b1 = bfromcstr("Hello");
	bstring b2 = bfromcstr("World");
	bstring b3 = bfromcstr("HELLO WORLD");


	mu_assert(bstricmp(b0, b0) == 0, "bstricmp: matching fails");

	mu_assert(bstricmp(b0, b1) > 0, "bstricmp: part matching fails");

	mu_assert(bstricmp(b1, b2) < 0, "bstricmp: non matching fails");

	mu_assert(bstricmp(b0, b3) == 0, "bstricmp: case insesitve matching failed");

	return NULL;
}

char * test_biseq()
{
	bstring b0 = bfromcstr("Hello");
	bstring b1 = bfromcstr("World");
	bstring b2 = bfromcstr(NULL);
	bstring b3 = bfromcstr("Hello");

	mu_assert(biseq(b0, b1) == 0, "biseq: un-equal strings should return 0");

	mu_assert(biseq(b0, b2) == -1, "biseq: a NULL string should return -1");

	mu_assert(biseq(b0, b3) == 1, "biseq: equal string should return 1");

	return NULL;
}

char * test_binstr()
{
	bstring to_search = bfromcstr("Hello World");

	int test = binstr(to_search, 0, bfromcstr("World"));
	int expect = 6;

	mu_assert(test == expect, "binstr: should return 6 when search for World, in Hello World starting from index 0");
	

	test = binstr(to_search, 6, bfromcstr("World"));
	expect = 6;

	mu_assert(test == expect, "binstr: should return 6 when searching for World, in Hello World starting from index 6");

	test = binstr(to_search, 7, bfromcstr("World"));
	expect = BSTR_ERR; // -1;

	mu_assert(test == expect, "binstr: should return -1 when searching for World, in Hello World starting from index 7");

	test = binstr(to_search, 0, bfromcstr("nope"));
	expect = BSTR_ERR;

	mu_assert(test = expect, "binstr: should return -1 when there is no match");
	return NULL;
}

char * test_bfindreplace()
{
	bstring b0 = bfromcstr("Hello there.");

	bstring to_find = bfromcstr("there");
	bstring to_replace = bfromcstr("World");

	bstring expect = bfromcstr("Hello World.");

	int return_code = bfindreplace(b0, to_find, to_replace, 0);
	
	mu_assert(return_code == BSTR_OK, "bfindreplace: returned non-ok value");

	int test = bstricmp(b0, expect);
	
	mu_assert(test == 0, "bfindreplace: string is not as expected.");
	
	return NULL;
}

char * test_bsplit()
{
	bstring b0 = bfromcstr("This\nString.");
	struct bstrList* test_list = bsplit(b0,  '\n');

	mu_assert(test_list->qty == 2, "bsplit: list length should be 2");
	// mu_assert(test_list[0]-> == "This", "bslpit: first entry not as expected");
	
	int test_entry0 = strcmp((const char *)test_list->entry[0]->data, "This");
	mu_assert(test_entry0 == 0, "bsplit: first entry not equal to \"This\"");

	int test_entry1 = strcmp((const char *)test_list->entry[1]->data, "String.");

	mu_assert(test_entry1 == 0, "bsplit: second entry not euqal to \"String.\"");
	
	return NULL;
}

char * test_bformat()
{
	bstring test_int = bformat("Int: %d", 0);
	int result_int = strcmp((const char *)test_int->data, "Int: 0");

	mu_assert(result_int == 0, "bformat: int test string fails");

	bstring test_str = bformat("String: %s", "yes");
	int result_str = strcmp((const char *)test_str->data, "String: yes");

	mu_assert(result_str == 0, "bformat: string test failed");

	return NULL;
}

char * test_blength()
{
	bstring test_str = bfromcstr("Hello, World.");
	int length = blength(test_str);

	mu_assert(length == 13, "blength: test string not expected length 13");

	test_str = bfromcstr("");
	length = blength(test_str);

	mu_assert(length == 0, "blength: test string not expected length of 0");

	return NULL;
}

char * test_bdata()
{
	bstring test_str = bfromcstr("Hello");
	const char * expect = "Hello";
	const char * value = bdata(test_str);
	
	int result = strcmp(value, expect);
	mu_assert(result == 0, "bdata: data is not expected value");

	return NULL;
}

char * test_bchar()
{
	bstring value = bfromcstr("Hello, World.");

	mu_assert(bchar(value, 0) == 'H', "bchar: character 0 is not 'H'");

	mu_assert(bchar(value, 13) == '\0', "bchar: character 13 is not '\\0'");

	mu_assert(bchar(value, 20) == '\0', "bchar: character 20 does not exist, should be \\0");
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
	mu_run_test(test_bconcat);
	mu_run_test(test_bstricmp);
	mu_run_test(test_biseq);
	mu_run_test(test_binstr);
	mu_run_test(test_bfindreplace);
	mu_run_test(test_bsplit);
	mu_run_test(test_bformat);
	mu_run_test(test_blength);
	mu_run_test(test_bdata);
	mu_run_test(test_bchar);

	return NULL;
}

RUN_TESTS(all_tests);
