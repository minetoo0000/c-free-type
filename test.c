#include "cobject.h"
#include <windows.h>


void array_tree( const let array, const uint64_t distant )
{
    if ( array.type != TYPE$Array );
    else if ( array.datas.Array.array_len <= 0 );
    else goto access;
    printf("\n value error!");
    return;

    access:;
    #define upper( number ) for(uint64_t i=0;i<number;i++)printf("    ")

    printf("{\n");
    for ( uint64_t i=0; i<array.datas.Array.array_len; i++ )
    {
        const let value = array.datas.Array.value[i];

        upper(distant+1);
        if ( value.type == TYPE$Bool )
            printf("%s,", value.datas.Bool.value?"true":"false");
        else if ( value.type == TYPE$Number )
            printf("%lf,", value.datas.Number.value);
        else if ( value.type == TYPE$Array )
            array_tree(value, distant+1);
        else if ( value.type == TYPE$String )
            printf("\"%s\",", value.datas.String.value);
        else if ( value.type == TYPE$null )
            printf("null,");
        else if ( value.type == TYPE$undefined )
            printf("undefined,");
        else
            printf("[Unknown Type],");

        printf("\n");
    }
    upper(distant);printf("},");

    #undef upper
}

int main( const int argc, const char*const args[] )
{
    let arr = Array(
        arrv(
            Number(11111),
            String("자바스크립트? 훗, 난 C언어로 자바스크립트 따라한다."),
            Bool(o_true),
            Bool(o_false),
            Array(
                3,
                (let[])
                {
                    String("C 언어, 반란의 시작..."),
                    Number(555),
                    arr,
                }
            ),
            Number(3405),
        )
    );
    let data = Array(
        arrv(
            arr,
            Number(1.2),
            Number(1.9999),
            Number(665.2),
            Bool(o_true),
            Array(
                6,
                (let[])
                {
                    String("여러분 이건 말도 안되요."),
                    String("이건 혁명입니다!!"),
                    String("C언어에서 이런 것이 정말로 가능합니다!!"),
                    String("사실 언어와 상관 없이 무엇이든 할 수 있지만"),
                    String("C언어에서는 다른 언어에선 당연한 것들이 새롭게 보입니다."),
                    arr,
                }
            ),
            Bool(o_false),
            Array(
                3,
                (let[])
                {
                    String("배열 내부 배열 내부 문자열"),
                    Bool(o_false),
                    arr,
                }
            ),
            String("아니아니아니아니아니아닝나이나아니아니아나ㅣ이ㅏㅇ낭아ㅣㅇ나아ㅣ"),
            arr,
        )
    );
    array_tree(data, 0);

    Array$.push(array, Number(55.55));
    let item = Array$.pop(array);
    

    getchar();
    return( 0 );    
}
