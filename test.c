#include "cobject.h"

void doit1( const int len, const var *const data_array )
{

    for ( int i=0; i<len; i++ )
    {
        printf("\n");
        if ( o_typeis(data_array[i]) == TYPE$Number )
        {
            printf("[%lf]", Get( Number, data_array[i] ));
        }
        else if ( o_typeis(data_array[i]) == TYPE$Bool )
        {
            printf("[%s]", Get( Bool, data_array[i] )?"true":"false");
        }
        else if ( o_typeis(data_array[i]) == TYPE$String )
        {
            printf("[%s]", Get( String, data_array[i] ));
        }

    }    
}

void doit( const var data )
{
    if ( Cobject.typeis(data) == TYPE$null )
    {
        printf("\n data는 null 입니다. 0은 아니고 추상적인 값입니다.");
    }
    else if ( o_typeis(data) == TYPE$String )
    {
        printf("\n data : \"%s\"", Get(String, data));
    }
    else if ( o_typeis(data) == TYPE$Array )
    {
        for ( int i=0; i<data.datas.Array.array_len; i++ )
        {
            printf("\n");
            if ( o_typeis(Get(Array, data)[i]) == TYPE$Number )
            {
                printf("[%lf]", Get( Number, Get(Array, data)[i] ));
            }
            else if ( o_typeis(Get(Array, data)[i]) == TYPE$Bool )
            {
                printf("[%s]", Get( Bool, Get(Array, data)[i] )?"true":"false");
            }
            else if ( o_typeis(Get(Array, data)[i]) == TYPE$String )
            {
                printf("[%s]", Get( String, Get(Array, data)[i] ));
            }

        }
    }
    else
    {
        printf("\n 예약된 타입만 사용 가능합니다.");
    }
}

int main( const int argc, const char*const args[] )
{
    var data = Array(
        6,
        (var[])
        {
            Number(1.2),
            Number(1.9999),
            Number(665.2),
            Bool(1),
            Bool(1),
            String("아니아니아니아니아니아닝나이나아니아니아나ㅣ이ㅏㅇ낭아ㅣㅇ나아ㅣ"),
        }
    );
    
    if(1)doit(
        Array(
            6,
            (var[])
            {
                Number(1.2),
                Number(1.9999),
                Number(665.2),
                Bool(1),
                Bool(1),
                String("아니아니아니아니아니아닝나이나아니아니아나ㅣ이ㅏㅇ낭아ㅣㅇ나아ㅣ"),
            }
        )
    );

    doit1(
        6,
        (var[])
        {
            Number(1.2),
            Number(1.9999),
            Number(665.2),
            Bool(1),
            Bool(1),
            String("아니아니아니아니아니아닝나이나아니아니아나ㅣ이ㅏㅇ낭아ㅣㅇ나아ㅣ"),
        }
    );


    var data1 = data;
    printf("\n is equel : %d", Get(Bool, Equel(data1, data1)));

    getchar();
    return( 0 );    
}
