#include "cobject.h"



int main()
{
    let array = Array(
        arrv(
            Number(21),
            String("자바스크립트 구경하고 가세요."),
            String("자바스크립트처럼 null, undefined 예외처리를 해보아요 ^^"),
            Array(
                4,
                (let[])
                {
                    Bool(o_true),
                    Bool(o_true),
                    Bool(o_false),
                    String("문자여얼"),
                }
            ),
        )
    );

    Array$.print_array_tree(array, 0, stdout);


    getchar();
    return( 0 );
}
