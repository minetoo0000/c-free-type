#include "cobject.h"



int main()
{
    let array = Array(
        arrv(
            Number(21),
            String("�ڹٽ�ũ��Ʈ �����ϰ� ������."),
            String("�ڹٽ�ũ��Ʈó�� null, undefined ����ó���� �غ��ƿ� ^^"),
            Array(
                4,
                (let[])
                {
                    Bool(o_true),
                    Bool(o_true),
                    Bool(o_false),
                    String("���ڿ���"),
                }
            ),
        )
    );

    Array$.print_array_tree(array, 0, stdout);


    getchar();
    return( 0 );
}
