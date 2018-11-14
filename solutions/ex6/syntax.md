Syntx

If-Statement
=====

    if(TEST) {
        CODE;
    } else if(TEST) {
        CODE;
    } else {
        CODE;
    }



Switch-Statement
=====

    switch (OPERAND) {
        case CONSTANT:
            CODE;
            break;
        default:
            CODE;
    }



While-Loop
==========

    while(TEST) {
        CODE;
    }



While with Continue
====

    while(TEST) {
        if(OTHER_TEST) {
            continue;
        }
        CODE;
    }



While with Break
=====

    while(TEST) {
        if(OTHER_TEST) {
            break;
        }
        CODE;
    }



Do-While
=====

    do {
        CODE;
    } while(TEST);



For-Loop
=====

    for(INIT; TEST; POST) {
        CODE;
    }

* *continue* and *break* work with *for*



Enum
=====

    enum { CONST1, CONST2, CONST3 } NAME;



Goto
====

    if(ERROR_TEST) {
        goto fail;
    }

    fail:
        CODE;



Functions
====

    TYPE NAME(ARG1, ARG2, ..) {
        CODE;
        return VALUE;
    }



Typedef
====

    typedef DEFINITION IDENTIFIER;


    typedef unsigned char byte;



Struct
====

    struct NAME {
        ELEMENTS;
    } [VARIABLE_NAME];



Typedef Struct
====

    typedef struct [STRUCT_NAME] {
        ELEMENTS;
    } IDENTIFIER;



Union
====

    union NAME {
        ELEMENTS;
    } [VARIABLE_NAME];

