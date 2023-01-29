#include "cobject.h"


struct test
{
    uint64_t v1;
    uint64_t v2;
    uint64_t v3;
};


var out( uint64_t type_size, ... )
{
    uint32_t len = type_size / sizeof(void**);
    uint64_t chunk[len];

    // printf("%llu", (getProp(type_size, uint64_t, 1)));
    for ( uint64_t i=0; i<len; i++ )
    {
        printf("[%llu]", getProp(type_size, uint64_t, i));
    }
    for ( uint64_t i=0; i<len; i++ )
    {
        chunk[i] = *(getProp(type_size, uint64_t*, 0)+i);
        // printf("[%llu]", chunk[i]);
    }
    printf("\n");

    return( *(var*)chunk );
}




int main( int argc, const char *const args[] )
{
    var data = Cobject.Number(12.34);
    var copy_data = out(sizeof(var), data, data, data);

    printf("data : %lf\n", data.datas.Number.value);
    printf("copy_data : %lf\n", copy_data.datas.Number.value);
    // for ( uint64_t i=0; i<3; i++ ) printf("[%llu]", ((uint64_t*)&copy_data)[i]);
    // printf("\n");
    // for ( uint64_t i=0; i<3; i++ ) printf("[%llu]", ((uint64_t*)&data)[i]);
    // printf("\n");
    
    getchar();
    return( 0 );
}