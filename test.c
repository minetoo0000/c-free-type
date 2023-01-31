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
            String("�ڹٽ�ũ��Ʈ? ��, �� C���� �ڹٽ�ũ��Ʈ �����Ѵ�."),
            Bool(o_true),
            Bool(o_false),
            Array(
                3,
                (let[])
                {
                    String("C ���, �ݶ��� ����..."),
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
                    String("������ �̰� ���� �ȵǿ�."),
                    String("�̰� �����Դϴ�!!"),
                    String("C���� �̷� ���� ������ �����մϴ�!!"),
                    String("��� ���� ��� ���� �����̵� �� �� ������"),
                    String("C������ �ٸ� ���� �翬�� �͵��� ���Ӱ� ���Դϴ�."),
                    arr,
                }
            ),
            Bool(o_false),
            Array(
                3,
                (let[])
                {
                    String("�迭 ���� �迭 ���� ���ڿ�"),
                    Bool(o_false),
                    arr,
                }
            ),
            String("�ƴϾƴϾƴϾƴϾƴϾƴ׳��̳��ƴϾƴϾƳ����̤������ƤӤ����Ƥ�"),
            arr,
        )
    );
    array_tree(data, 0);

    Array$.push(array, Number(55.55));
    let item = Array$.pop(array);
    

    getchar();
    return( 0 );    
}
