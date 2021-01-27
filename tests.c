//*****************************************************
// Filename: tests.c (unit tests for the game logic)
//
// Author: Nandigam
//*****************************************************

#include "CuTest.h"
#include "othello.h"
    
void test_initializeBoard_1(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    char *actual = toString(size,board);
    char *expected = "  1 2 3 4\n1 - - - -\n2 - B W -\n3 - W B -\n4 - - - -\n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
}

void test_initializeBoard_2(CuTest *tc) {
    int size = 6;
    char board[size][size];
	initializeBoard(size,board);
	initializeBoard(size,board);
    char *actual = toString(size,board);
    char *expected = "  1 2 3 4 5 6\n1 - - - - - -\n2 - - - - - -\n3 - - B W - -\n4 - - W B - -\n5 - - - - - -\n6 - - - - - -\n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
}

void test_initializeBoard_3(CuTest *tc) {
    int size = 8;
    char board[size][size];
	initializeBoard(size,board);
	initializeBoard(size,board);
    char *actual = toString(size,board);
    char *expected = "  1 2 3 4 5 6 7 8\n1 - - - - - - - -\n2 - - - - - - - -\n3 - - - - - - - -\n4 - - - B W - - -\n5 - - - W B - - -\n6 - - - - - - - -\n7 - - - - - - - -\n8 - - - - - - - -\n";
    CuAssertStrEquals(tc, expected, actual);
    free(actual);
}

void test_isGameOver(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, !isGameOver(size,board));
}

void test_isBoardFull_1(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, !isBoardFull(size,board));
}

void test_isBoardFull_2(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    placeDiscAt(size,board,1,3,BLACK);
    placeDiscAt(size,board,0,3,WHITE);
    placeDiscAt(size,board,0,2,BLACK);
    placeDiscAt(size,board,0,1,WHITE);
    placeDiscAt(size,board,3,0,BLACK);
    placeDiscAt(size,board,3,2,WHITE);
    placeDiscAt(size,board,1,0,BLACK);
    placeDiscAt(size,board,2,0,WHITE);
    placeDiscAt(size,board,3,1,BLACK);
    placeDiscAt(size,board,3,3,WHITE);
    placeDiscAt(size,board,0,0,WHITE);
    placeDiscAt(size,board,2,3,WHITE);
    CuAssertTrue(tc, isBoardFull(size,board));
}

void test_isValidMove_1(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, isValidMove(size,board,0,2,BLACK));
    CuAssertTrue(tc, isValidMove(size,board,1,3,BLACK));
    CuAssertTrue(tc, isValidMove(size,board,2,0,BLACK));
    CuAssertTrue(tc, isValidMove(size,board,3,1,BLACK));
}

void test_isValidMove_2(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, isValidMove(size,board,0,1,WHITE));
    CuAssertTrue(tc, isValidMove(size,board,1,0,WHITE));
    CuAssertTrue(tc, isValidMove(size,board,2,3,WHITE));
    CuAssertTrue(tc, isValidMove(size,board,3,2,WHITE));
}

void test_isValidMove_3(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, !isValidMove(size,board,0,0,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,0,1,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,0,3,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,1,0,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,2,3,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,3,0,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,3,2,BLACK));
    CuAssertTrue(tc, !isValidMove(size,board,3,3,BLACK));
}

void test_isValidMove_4(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, !isValidMove(size,board,0,0,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,0,2,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,0,3,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,1,3,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,2,0,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,3,0,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,3,1,WHITE));
    CuAssertTrue(tc, !isValidMove(size,board,3,3,WHITE));
}

void test_isValidMoveAvailable_1(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, isValidMoveAvailable(size,board,WHITE));
}

void test_isValidMoveAvailable_2(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    CuAssertTrue(tc, isValidMoveAvailable(size,board,BLACK));
}

void test_isValidMoveAvailable_3(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    placeDiscAt(size,board,1,3,BLACK);
    placeDiscAt(size,board,0,3,WHITE);
    placeDiscAt(size,board,0,2,BLACK);
    placeDiscAt(size,board,0,1,WHITE);
    placeDiscAt(size,board,3,0,BLACK);
    placeDiscAt(size,board,3,2,WHITE);
    placeDiscAt(size,board,1,0,BLACK);
    placeDiscAt(size,board,2,0,WHITE);
    placeDiscAt(size,board,3,1,BLACK);
    placeDiscAt(size,board,3,3,WHITE);
    CuAssertTrue(tc, !isValidMoveAvailable(size,board,BLACK));
    placeDiscAt(size,board,0,0,WHITE);
    CuAssertTrue(tc, !isValidMoveAvailable(size,board,BLACK));
    placeDiscAt(size,board,2,3,WHITE);
    CuAssertTrue(tc, isBoardFull(size,board));
    CuAssertTrue(tc, isGameOver(size,board));
    CuAssertIntEquals(tc, WHITE, checkWinner(size,board));
}

void test_gameplay_1(CuTest *tc) {
    int size = 4;
    char board[size][size];
	initializeBoard(size,board);
    placeDiscAt(size,board,1,3,BLACK);
    placeDiscAt(size,board,0,3,WHITE);
    placeDiscAt(size,board,0,2,BLACK);
    placeDiscAt(size,board,0,1,WHITE);
    placeDiscAt(size,board,3,0,BLACK);
    placeDiscAt(size,board,3,2,WHITE);
    placeDiscAt(size,board,1,0,BLACK);
    placeDiscAt(size,board,2,0,WHITE);
    placeDiscAt(size,board,3,1,BLACK);
    placeDiscAt(size,board,3,3,WHITE);
    // no valid move for BLACK piece, WHITE goes again
    placeDiscAt(size,board,0,0,WHITE);
    // no valid move for BLACK piece, WHITE goes again
    placeDiscAt(size,board,2,3,WHITE);
    CuAssertTrue(tc, isGameOver(size,board));
    CuAssertIntEquals(tc, WHITE, checkWinner(size,board));
}

void test_gameplay_2(CuTest *tc) {
    int size = 6;
    char board[size][size];
	initializeBoard(size,board);
    placeDiscAt(size,board,2,1,WHITE);
    placeDiscAt(size,board,1,3,BLACK);
    placeDiscAt(size,board,2,4,WHITE);
    placeDiscAt(size,board,3,5,BLACK);
    placeDiscAt(size,board,4,4,WHITE);
    placeDiscAt(size,board,2,0,BLACK);
    placeDiscAt(size,board,1,1,WHITE);
    placeDiscAt(size,board,0,1,BLACK);
    placeDiscAt(size,board,0,0,WHITE);
    placeDiscAt(size,board,4,1,BLACK);
    placeDiscAt(size,board,2,5,WHITE);
    placeDiscAt(size,board,4,3,BLACK);
    placeDiscAt(size,board,4,2,WHITE);
    placeDiscAt(size,board,4,5,BLACK);
    placeDiscAt(size,board,5,5,WHITE);
    placeDiscAt(size,board,1,2,BLACK);
    placeDiscAt(size,board,4,0,WHITE);
    placeDiscAt(size,board,5,3,BLACK);
    placeDiscAt(size,board,1,4,WHITE);
    placeDiscAt(size,board,0,3,BLACK);
    placeDiscAt(size,board,0,2,WHITE);
    placeDiscAt(size,board,5,0,BLACK);
    placeDiscAt(size,board,3,1,WHITE);
    placeDiscAt(size,board,0,5,BLACK);
    placeDiscAt(size,board,3,4,WHITE);
    placeDiscAt(size,board,5,4,BLACK);
    placeDiscAt(size,board,5,1,WHITE);
    placeDiscAt(size,board,1,0,BLACK);
    placeDiscAt(size,board,0,4,WHITE);
    placeDiscAt(size,board,5,2,BLACK);
    placeDiscAt(size,board,3,0,WHITE);
    // no valid move for BLACK piece, WHITE goes again
    placeDiscAt(size,board,1,5,WHITE);
    CuAssertTrue(tc, isGameOver(size,board));
    CuAssertIntEquals(tc, WHITE, checkWinner(size,board));
}

void test_gameplay_3(CuTest *tc) {
    int size = 8;
    char board[size][size];
	initializeBoard(size,board);
    placeDiscAt(size,board,5,3,BLACK);
    placeDiscAt(size,board,5,2,WHITE);
    placeDiscAt(size,board,3,5,BLACK);
    placeDiscAt(size,board,2,5,WHITE);
    placeDiscAt(size,board,4,2,BLACK);
    placeDiscAt(size,board,3,6,WHITE);
    placeDiscAt(size,board,3,7,BLACK);
    placeDiscAt(size,board,3,2,WHITE);
    placeDiscAt(size,board,1,6,BLACK);
    placeDiscAt(size,board,0,7,WHITE);
    placeDiscAt(size,board,4,1,BLACK);
    placeDiscAt(size,board,5,4,WHITE);
    placeDiscAt(size,board,6,3,BLACK);
    placeDiscAt(size,board,6,2,WHITE);
    placeDiscAt(size,board,6,1,BLACK);
    placeDiscAt(size,board,7,2,WHITE);
    placeDiscAt(size,board,7,1,BLACK);
    placeDiscAt(size,board,2,3,WHITE);
    placeDiscAt(size,board,3,1,BLACK);
    placeDiscAt(size,board,2,4,WHITE);
    placeDiscAt(size,board,6,5,BLACK);
    placeDiscAt(size,board,6,0,WHITE);
    placeDiscAt(size,board,1,4,BLACK);
    placeDiscAt(size,board,2,6,WHITE);
    placeDiscAt(size,board,7,3,BLACK);
    placeDiscAt(size,board,5,5,WHITE);
    placeDiscAt(size,board,4,5,BLACK);
    placeDiscAt(size,board,4,6,WHITE);
    placeDiscAt(size,board,4,7,BLACK);
    placeDiscAt(size,board,2,0,WHITE);
    placeDiscAt(size,board,5,1,BLACK);
    placeDiscAt(size,board,6,4,WHITE);
    placeDiscAt(size,board,3,0,BLACK);
    placeDiscAt(size,board,2,2,WHITE);
    placeDiscAt(size,board,1,2,BLACK);
    placeDiscAt(size,board,5,6,WHITE);
    placeDiscAt(size,board,5,7,BLACK);
    placeDiscAt(size,board,0,2,WHITE);
    placeDiscAt(size,board,2,7,BLACK);
    placeDiscAt(size,board,6,6,WHITE);
    placeDiscAt(size,board,7,4,BLACK);
    placeDiscAt(size,board,7,5,WHITE);
    placeDiscAt(size,board,6,7,BLACK);
    placeDiscAt(size,board,7,0,WHITE);
    placeDiscAt(size,board,0,6,BLACK);
    placeDiscAt(size,board,5,0,WHITE);
    placeDiscAt(size,board,4,0,BLACK);
    placeDiscAt(size,board,7,6,WHITE);
    placeDiscAt(size,board,2,1,BLACK);
    placeDiscAt(size,board,1,5,WHITE);
    placeDiscAt(size,board,1,3,BLACK);
    placeDiscAt(size,board,7,7,WHITE);
    placeDiscAt(size,board,0,5,BLACK);
    placeDiscAt(size,board,1,7,WHITE);
    placeDiscAt(size,board,0,3,BLACK);
    placeDiscAt(size,board,0,4,WHITE);
    placeDiscAt(size,board,1,0,BLACK);
    placeDiscAt(size,board,0,1,WHITE);
    placeDiscAt(size,board,1,1,BLACK);
    placeDiscAt(size,board,0,0,WHITE);
    CuAssertTrue(tc, isGameOver(size,board));
    CuAssertIntEquals(tc, WHITE, checkWinner(size,board));
}

CuSuite* StrUtilGetSuite() {
    CuSuite* suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, test_initializeBoard_1);
    SUITE_ADD_TEST(suite, test_initializeBoard_2);
    SUITE_ADD_TEST(suite, test_initializeBoard_3);
    SUITE_ADD_TEST(suite, test_isGameOver);
    SUITE_ADD_TEST(suite, test_isBoardFull_1);
    SUITE_ADD_TEST(suite, test_isBoardFull_2);
    SUITE_ADD_TEST(suite, test_isValidMove_1);
    SUITE_ADD_TEST(suite, test_isValidMove_2);
    SUITE_ADD_TEST(suite, test_isValidMove_3);
    SUITE_ADD_TEST(suite, test_isValidMove_4);
    SUITE_ADD_TEST(suite, test_isValidMoveAvailable_1);
    SUITE_ADD_TEST(suite, test_isValidMoveAvailable_2);
    SUITE_ADD_TEST(suite, test_isValidMoveAvailable_3);
    SUITE_ADD_TEST(suite, test_gameplay_1);
    SUITE_ADD_TEST(suite, test_gameplay_2);
    SUITE_ADD_TEST(suite, test_gameplay_3);
    return suite;
}
    
void RunAllTests(void) {
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
        
    CuSuiteAddSuite(suite, StrUtilGetSuite());
    
    CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
}
    
int main(void) {
    RunAllTests();
}
