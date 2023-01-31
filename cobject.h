#pragma once


#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <string.h>


#define DEFINE_TEXT(TEXT)   #TEXT
#define LOG(NOTICE_TEXT)   _Pragma(DEFINE_TEXT(message("[ LOG ] : " #NOTICE_TEXT)))

#define o_getVerify(VAR_DATA)   ((uint8_t)( ~(uint64_t)(&VAR_DATA) ))

#define o_true   1
#define o_false   0
#define true   (Cobject.Bool(o_true))
#define false   (Cobject.Bool(o_false))

#define o_void   ((void)0)
#define o_null   ((uint8_t)0)

#define TYPE$undefined   (int8_t)-1
#define TYPE$null   (int8_t)0
#define TYPE$Bool   (int8_t)1
#define TYPE$Number   (int8_t)2
#define TYPE$Array   (int8_t)3
#define TYPE$String   (int8_t)4
#define TYPE$Json   (int8_t)5
#define TYPE$Mem   (int8_t)6

#define o_typeis( VAR_DATA )   (VAR_DATA.type)

#define o_Function(RETURN_TYPE, FUNC_ID, CODE, ...)\
({\
	RETURN_TYPE Cobject$Utility$Function$return_value_##FUNC_ID;\
	CODE,##__VA_ARGS__\
	Cobject$Utility$Function$goto_##FUNC_ID:(RETURN_TYPE)Cobject$Utility$Function$return_value_##FUNC_ID;\
})

// #define Function(INLINE_CODE, RETURN_VAR_VALUE)\
// ({INLINE_CODE ((return_state_t)Cobject.Return(RETURN_VAR_VALUE));})

#define Freturn( FUNC_ID, RETURN_VALUE )\
({Cobject$Utility$Function$return_value_##FUNC_ID=RETURN_VALUE;goto Cobject$Utility$Function$goto_##FUNC_ID;})

/// 더이상 사용되지 않는다. ///
// #define Var(VAR_TYPE, VAR_NAME, ...)\
// let VAR_NAME=Cobject.VAR_TYPE(__VA_ARGS__);Cobject.Update(&VAR_NAME)

// #define Auto(VAR_TYPE, VAR_NAME, ...)\
// let VAR_NAME=0;case __COUNTER__+1:;Cobject$Memory$AutoUnload$is_unload==0?({VAR_NAME=Cobject.VAR_TYPE(__VA_ARGS__);Cobject.Update(&VAR_NAME);Cobject$Memory$AutoUnload$var_count++;}):({Cobject.Unload(VAR_NAME);Cobject$Memory$AutoUnload$unload_pointer+=1;break;});

// #define Run(VARS, INLINE_CODE)\
// {\
// 	uint8_t Cobject$Memory$AutoUnload$is_unload=0;\
// 	uint8_t Cobject$Memory$AutoUnload$is_scan=1;\
// 	uint16_t Cobject$Memory$AutoUnload$unload_pointer=0;\
// 	uint16_t Cobject$Memory$AutoUnload$var_count=0;\
// 	\
// 	while(Cobject$Memory$AutoUnload$is_scan==1){\
// 		switch(Cobject$Memory$AutoUnload$unload_pointer){\
// 			case 0:;\
// 			VARS\
// 			INLINE_CODE\
// 			Cobject$Memory$AutoUnload$is_unload=1;\
// 			if(Cobject$Memory$AutoUnload$var_count==0){Cobject$Memory$AutoUnload$is_scan=0;break;}\
// 			Cobject$Memory$AutoUnload$unload_pointer==0?(Cobject$Memory$AutoUnload$unload_pointer=__COUNTER__+1-Cobject$Memory$AutoUnload$var_count):0;\
// 			break;\
// 			default:;Cobject$Memory$AutoUnload$is_scan=0;\
// 		}\
// 	}\
// }

#define Get(VAR_TYPE, VAR_DATA)\
(VAR_DATA.datas.VAR_TYPE.value)

// 가변 인자를 가져온다. 시스템 bit 수 크기 까지만 정상적으로 가져올 수 있다. (64bit, 32bit)
#define getProp(START_VAR, GET_TYPE, INDEX)   (*(GET_TYPE*)((((void**)&(START_VAR)))+(1+INDEX)))

#define o_arraylen( ARRAY_TYPE, ARRAY )\
sizeof(ARRAY)/sizeof(ARRAY_TYPE)

#define arr( ARRAY_TYPE, ARRAY_VALUE, ... )\
(sizeof((ARRAY_TYPE[]){ARRAY_VALUE,##__VA_ARGS__})/sizeof(ARRAY_TYPE)),([ARRAY_TYPE]){ARRAY_VALUE,##__VA_ARGS__}

#define arrv( ARRAY_VALUE, ... )\
(sizeof((let[]){ARRAY_VALUE,##__VA_ARGS__})/sizeof(let)),(let[]){ARRAY_VALUE,##__VA_ARGS__}

#define AppExit( RETURN_CODE )\
Cobject$Utility$Thread$value_kit=(struct type$class_Cobject$Utility$Thread$value_kit){.exit_code=RETURN_CODE,.is_exit=o_true};return

#define setupThread(...)\
static void(*Cobject$Utility$Thread$setupThread[])( const int argc, const char*const args[] )={__VA_ARGS__}

#define loopThread(...)\
static void(*Cobject$Utility$Thread$loopThread[])( const int argc, const char*const args[] )={__VA_ARGS__}

#define startThread()\
int main( const int argc, const char*const args[] )\
{\
	uint16_t setup_count = sizeof(Cobject$Utility$Thread$setupThread) / sizeof(void(*)());\
	uint16_t loop_count = sizeof(Cobject$Utility$Thread$loopThread) / sizeof(void(*)());\
	for ( uint16_t index=0; index<setup_count; index++ )\
	{\
		(Cobject$Utility$Thread$value_kit.is_exit==o_false)?(Cobject$Utility$Thread$setupThread[index](), 0):(({return(Cobject$Utility$Thread$value_kit.exit_code); 0;}));\
	}\
	for ( uint16_t index=0; o_true; index++ )\
	{\
		if ( index >= loop_count )\
		{\
			index = 0;\
		}\
		(Cobject$Utility$Thread$value_kit.is_exit==o_false)?(Cobject$Utility$Thread$loopThread[index](), 0):(({return(Cobject$Utility$Thread$value_kit.exit_code);0;}));\
	}\
}




typedef struct _bool_t
{
	uint8_t value : 1;
} bool_t;

typedef double type$number_t$value;
typedef struct _number_t
{
	type$number_t$value value;
} number_t;

typedef uint64_t type$array_t$array_len;
typedef void* type$array_t$value;

typedef uint16_t type$string_t$string_len;
typedef uint16_t type$string_t$string_size;
typedef char type$string_t$value;
typedef struct _string_t
{
	type$string_t$string_size string_size;
	type$string_t$value* value;
} string_t;

typedef struct _null_t
{
	uint8_t value : 1;
} null_t;

typedef struct _undefined_t
{
	uint8_t value : 1;
} undefined_t;

typedef struct _mem_t
{
	uint8_t is_free : 1;
	uint64_t byte_size;
	// value : 메모리 주소.
	void *value;
} mem_t;




typedef struct type$class_Cobject$Object_type$let
{
	int8_t type : 7;
	union _datas
	{
		bool_t Bool;
		number_t Number;
		struct _array_t
		{
			type$array_t$array_len array_len;
			struct type$class_Cobject$Object_type$let* value;
		} Array;
		string_t String;
		null_t Null;
		undefined_t Undefined;
		mem_t Mem;
	} datas;
} let;


typedef uint8_t type$return_state_t$log; 
typedef struct _return_state_t
{
	const uint8_t success : 7;
	const type$return_state_t$log* const log;
	const let data;
} return_state_t;




const let f$Cobject$Mem( const uint64_t byte_size )
{
	let result = {
		.type = TYPE$null,
		.datas.Null.value = 0,
	};
	// fail
	if ( !byte_size ) return( result );

	void *mem_space = malloc(byte_size);

	// fail
	if ( !mem_space ) return( result );
	
	// success
	result = (let){
		.type = TYPE$Mem,
		.datas.Mem = {
			.is_free = 0,
			.byte_size = byte_size,
			.value = mem_space,
		},
	};
	return( result );
}
const let(*const Mem)( const uint64_t byte_size ) = f$Cobject$Mem;


const let f$Cobject$resizeMem( const let mem, const let new_byte_size )
{
	let result = {
		.type = TYPE$null,
		.datas.Null.value = 0,
	};
	
	if ( mem.type != TYPE$Mem );
	else if ( mem.datas.Mem.is_free );
	else if ( mem.datas.Mem.value == 0 );
	else if ( new_byte_size.type != TYPE$Number );
	else if ( mem.datas.Mem.byte_size == (uint64_t)new_byte_size.datas.Number.value );
	else if ( (uint64_t)new_byte_size.datas.Number.value <= 0 );
	else goto access;
	return( result );

	access:;
	void *const new_space = realloc(mem.datas.Mem.value, (uint64_t)new_byte_size.datas.Number.value);

	if ( new_space == 0 );
	else goto success;
	return( result );

	success:;
	result = (let){
		.type = TYPE$Mem,
		.datas.Mem = {
			.is_free = 0,
			.byte_size = (uint64_t)new_byte_size.datas.Number.value,
			.value = new_space,
		},
	};
	return( result );
}
const let(*const resizeMem)( const let mem, const let new_byte_size ) = f$Cobject$resizeMem;


void method$class_Cobject$Unload(let *const data)
{
	switch ( data->type )
	{
		case TYPE$Array : free( data->datas.Array.value );
		goto OUT;

		case TYPE$String : free( data->datas.String.value );
		goto OUT;

		case TYPE$Mem : free( data->datas.Mem.value );
		goto OUT;


		OUT:
		default:
		*data = (let){
			.type = TYPE$null,
			.datas.Null.value = 0,
		};
	}
}
void(*const Unload)(let *const data) = method$class_Cobject$Unload;


static let method$class_Cobject$Bool(uint8_t bool)
{
	return(
		(let)
		{
			.type = TYPE$Bool,
			.datas = {
				.Bool = {
					.value = bool,
				},
			},
		}
	);
}
let(*const Bool)(uint8_t bool) = method$class_Cobject$Bool;


static let method$class_Cobject$Number(type$number_t$value number)
{
	return(
		(let)
		{
			.type = TYPE$Number,
			.datas = {
				.Number = {
					.value = number,
				},
			},
		}
	);
}
let(*const Number)(type$number_t$value number) = method$class_Cobject$Number;


static let method$class_Cobject$Array(const type$array_t$array_len array_len, const let *const var_data_array )
{

	
	// let *const output_array = (let*)calloc(array_len, sizeof(let));
	// for ( type$array_t$array_len index=0; index<array_len; index++ )
	// {
	// 	output_array[index] = var_data_array[index];
	// }
	
	// return(
	// 	(let)
	// 	{
	// 		.type = TYPE$Array,
	// 		.datas = {
	// 			.Array = {
	// 				.array_len = array_len,
	// 				.value = output_array,
	// 			},
	// 		},
	// 	}
	// );
}
let(*const Array)( type$array_t$array_len array_len, const let *const var_data_array ) = method$class_Cobject$Array;


let method$class_Cobject$String(const type$string_t$value* const string)
{
	type$string_t$value* output_string = (type$string_t$value*)calloc(strlen((char*)string)+sizeof(type$string_t$value), sizeof(type$string_t$value));
	for ( uint64_t i=0; i<=strlen((char*)string); i++ ) output_string[i] = string[i];

	return(
		(let)
		{
			.type = TYPE$String,
			.datas = {
				.String = {
					.string_size = strlen((char*)output_string),
					.value = output_string,
				},
			},
		}
	);
}
let(*const String)(const type$string_t$value* const string) = method$class_Cobject$String;


let method$class_Cobject$Null()
{
	return(
		(let)
		{
			.type = TYPE$null,
			.datas = 0,
		}
	);
}
let(*const Null)() = method$class_Cobject$Null;


let method$class_Cobject$Undefined()
{
	return(
		(let)
		{
			.type = TYPE$undefined,
			.datas = 0,
		}
	);
}
let(*const Undefined)() = method$class_Cobject$Undefined;


let method$class_Cobject$Equel( const let get0, const let get1 )
{
	if ( get0.type == get1.type )
	{
		if ( get0.type == TYPE$Bool )
		{
			return ( get0.datas.Bool.value == get1.datas.Bool.value ) ? ( Bool(o_true) ) : ( Bool(o_false) );
		}
		else if ( get0.type == TYPE$Number )
		{
			return( get0.datas.Number.value == get1.datas.Number.value ) ? ( Bool(o_true) ) : ( Bool(o_false) );
		}
		else if ( get0.type == TYPE$Array )
		{
			if ( get0.datas.Array.array_len != get1.datas.Array.array_len ) return( Bool(o_false) );
			for ( uint64_t i=0; i<get0.datas.Array.array_len; i++ )
			{
				const let data0 = get0.datas.Array.value[i];
				const let data1 = get1.datas.Array.value[i];
				if ( !method$class_Cobject$Equel(data0, data1).datas.Bool.value ) return( Bool(o_false) );
			}
			return( Bool(o_true) );
		}
		else if ( get0.type == TYPE$String )
		{
			if ( get0.datas.String.string_size != get1.datas.String.string_size ) return( Bool(o_false) );
			return( Bool(!!!strcmp((char*)get0.datas.String.value, (char*)get1.datas.String.value)) );
		}
		else if ( get0.type == TYPE$null )
		{
			return( Bool(o_true) );
		}
		else if ( get0.type == TYPE$undefined )
		{
			return( Bool(o_true) );
		}
		else
		{
			return( Bool(o_false) );
		}

	}
	else
	{
		return( Bool(o_false) );
	}
}
let(*const Equel)( const let get0, const let get1 ) = method$class_Cobject$Equel;


int f$Cobject$typeis( const let data )
{
	return( data.type );
}


let f$Cobject$Array$push( let array, const let value )
{

}


struct class$Cobject
{
	let(*const Bool)(uint8_t bool);
	let(*const Number)(type$number_t$value number);
	let(*const Array)(type$array_t$array_len array_len, const let *const var_data_array);
	let(*const String)(const type$string_t$value* const string);
	let(*const Null)();
	let(*const Undefined)();
	const let(*const Mem)( const uint64_t byte_size );

	void(*const Unload)(let *const data);
	let(*const Equel)( const let get0, const let get1 );
	int(*const typeis)( const let data );
	const let(*const resizeMem)( const let mem, const let new_byte_size );
} Cobject = {
	.Bool = method$class_Cobject$Bool,
	.Number = method$class_Cobject$Number,
	.Array = method$class_Cobject$Array,
	.String = method$class_Cobject$String,
	.Null = method$class_Cobject$Null,
	.Undefined = method$class_Cobject$Undefined,
	.Mem = f$Cobject$Mem,

	.Unload = method$class_Cobject$Unload,
	.Equel = method$class_Cobject$Equel,
	.typeis = f$Cobject$typeis,
	.resizeMem = f$Cobject$resizeMem,
};

struct type$class_Cobject$Utility$Thread$value_kit
{
	uint8_t is_exit:4;
	int16_t exit_code:12;
} Cobject$Utility$Thread$value_kit = {
	.exit_code = 0,
	.is_exit = o_false,
};
