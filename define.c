#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#define DECLARE(name, type) type name##_##type##_type
int __cdecl func(int a, int b)
{
    printf("%d, %d\n", a, b);
}
/*£¨×ªÔØ£©
 * A simple printf function. Only support the following format:
 * Code Format
 * %c character
 * %d signed integers
 * %i signed integers
 * %s a string of characters
 * %o octal
 * %x unsigned hexadecimal
 */
int my_printf( const char* format, ...)
{
    va_list arg;
    int done = 0;

    va_start (arg, format);

    while( *format != '\0')
    {
        if( *format == '%')
        {
            if( *(format+1) == 'c' )
            {
                char c = (char)va_arg(arg, int);
                putc(c, stdout);
            } else if( *(format+1) == 'd' || *(format+1) == 'i')
            {
                char store[20];
                int i = va_arg(arg, int);
                char* str = store;
                itoa(i, store, 10);
                while( *str != '\0') putc(*str++, stdout);
            } else if( *(format+1) == 'o')
            {
                char store[20];
                int i = va_arg(arg, int);
                char* str = store;
                itoa(i, store, 8);
                while( *str != '\0') putc(*str++, stdout);
            } else if( *(format+1) == 'x')
            {
                char store[20];
                int i = va_arg(arg, int);
                char* str = store;
                itoa(i, store, 16);
                while( *str != '\0') putc(*str++, stdout);
            } else if( *(format+1) == 's' )
            {
                char* str = va_arg(arg, char*);
                while( *str != '\0') putc(*str++, stdout);
            }

            // Skip this two characters.

            format += 2;
        } else {
            putc(*format++, stdout);
        }
    }

    va_end (arg);

    return done;
}
void GetMemory(char **p)
{
    *p = (char *)malloc(100);
    //*p = (char *)malloc(100);
}
void Test(void)
{
    char *str = NULL;
    GetMemory(&str);
    strcpy(str,"hello world\n");
    if (NULL != str)
    {
        printf(str);
        free(str);
        str = NULL;
    }
}

#define OK    1
#define ERROR 0

int str_str(const char *str1, const char *str2)
{
    const char *s1 = NULL;
    const char *s2 = NULL;

    if (str1 == NULL)
    {
        return (str2 == NULL) ? OK : ERROR;
    }

    if (str2 == NULL)
    {
        return OK;
    }

    for (; *str1 != '\0'; str1++)
    {
        if (*str1 == *str2)
        {
            for (s1 = str1, s2 = str2; ; )
            {
                if (*++s2 == '\0')
                {
                    return OK;
                }
                else if (*++s1 != *s2)
                {
                    break;
                }
            }
        }
    }

    return ERROR;
}
int main()
{
    DECLARE(val, int);
    val_int_type = 10;
    printf("%d\n", val_int_type);
    printf("sizeof(void) %d, sizeof(void *) %d\n", sizeof(void), sizeof(void *));
    //printf("%s\n", DECLARE(val, int));
    struct tag
    {
        char a;
        int b;
    }x = {'A',1};
    printf("%c, %d\n", x.a, x.b);
    struct test
    {
        char a;
        int b;
    };
    struct test y = {'A', 1};
    printf("%c, %d\n", y.a, y.b);
    struct test z = {.a = 'A', .b = 1};
    printf("%c, %d\n", z.a, z.b);
    struct st1
    {
        unsigned char a:7;
        unsigned char b:2;
        unsigned char c:7;
    }s1;
    printf("sizeof s1 %d\n", sizeof(s1));
    struct st2
    {
        unsigned int a:31;
        unsigned int b:2;
        unsigned int c:31;
    }s2;
    printf("sizeof s2 %d\n", sizeof(s2));

    typedef struct st
    {
        int a;
        int b;
        char c[0];
    }st_t;
    printf("----%d\n", sizeof(st_t));

    #define SIZE 100
    st_t *s = (st_t*)malloc(sizeof(st_t)+SIZE);
    memset(s, 0, sizeof(st_t)+SIZE);
    strncpy(s->c, "huang", strlen("huang"));
    printf("%s\n", s->c);

    int i=0;
    func(i++, i++);
    my_printf("%s\n", "huangshengbinisagenius");
    Test();
    int ret;
    char str1[100] = "huangshengbin";
    char str2[100] = "huang";
    ret = str_str(str1, str2);
    if (OK == ret)
    {
        printf("str2 in str1\n");
    }
    else
    {
        printf("no\n");
    }
    system("pause");
    return 0;
}
