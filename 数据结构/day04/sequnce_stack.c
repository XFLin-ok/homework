#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// 数据类型
typedef char data_t;
// 管理节点类型
typedef struct sequnce_stack
{
    data_t *bottom;
    int top;
    int size;
} sequnce_stack;
// 创建空栈
sequnce_stack *sequncestack_create(int size)
{
    // 申请堆空间
    sequnce_stack *mange = (sequnce_stack *)malloc(1 * sizeof(sequnce_stack));
    if (mange == NULL)
    {
        printf("mange malloc fail\n");
        return NULL;
    }
    // 初始化
    mange->size = size;
    mange->top = -1;
    mange->bottom = (data_t *)malloc(1 * sizeof(data_t));
    if (mange->bottom == NULL)
    {
        printf("bottom malloc fail\n");
        return NULL;
    }
    return mange;
}
// 入栈
bool sequencestack_PUSH(sequnce_stack *mange, data_t data)
{
    mange->top++;
    mange->bottom[mange->top] = data;

    return true;
}
// 出栈
data_t sequencestack_POP(sequnce_stack *mange)
{
    data_t tmp = 0;
    tmp = mange->bottom[mange->top];
    if (mange->top == -1)
    {
        printf("stack is empty\n");
        return false;
    }
    mange->top--;
    return tmp;
}
// 判断字符串是否有效
void judgment_str()
{
    sequnce_stack *mange1 = sequncestack_create(100);
    int i = 0;
    char str[100] = {0};
    printf("请输入表达式:\n");
    scanf("%s", str);
    while (str[i] != '\0')
    {
        if (str[i] == '(')
        {
            sequencestack_PUSH(mange1, str[i]);
        }
        if (str[i] == ')')
        {
            sequencestack_POP(mange1);
        }
        i++;
    }
    if (mange1->top == -1)
    {
        printf("表达式正确!\n");
    }
    else
    {
        printf("表达式错误!\n");
    }
}

//  打印
bool sequencestack_print(sequnce_stack *mange)
{
    if (mange->top == -1)
    {
        printf("stack is empty\n");
        return false;
    }
    int i;
    for (i = mange->top; i >= 0; i--)
    {
        printf("%d\t", mange->bottom[i]);
    }
    printf("\n");
}

int main()
{
    // sequnce_stack *mange = sequncestack_create(10);

    // sequencestack_PUSH(mange, 10);
    // sequencestack_PUSH(mange, 20);
    // sequencestack_PUSH(mange, 30);

    // sequencestack_print(mange);

    // data_t last = sequencestack_POP(mange);
    // sequencestack_print(mange);
    // printf("%d\n", last);

    judgment_str();
}