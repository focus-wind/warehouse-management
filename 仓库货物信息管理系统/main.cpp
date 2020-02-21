/***********************************
    @名称：仓库货物信息管理系统设计
    @author：super-so,
    @create：2019.12.30~2019.12.31
************************************/
#include "head.h"

int main()
{
    int n=0,i=0,user,j=0;                       //n表示调用的函数功能，i表示结构体个数
    char a[500]="\n\n\n\n\n\n\n\n\n\n\n\n\n==========================================================================\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n-------------------------仓库货物信息管理系统设计------------------------\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n||\t\t\t\t\t\t\t\t\t||\n==========================================================================\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    while(a[j]!='\0')
    {
        Sleep(10);
        printf("%c",a[j]);
        j++;
    }
    user=users();
    if(user==1)
    {
        menu();
        scanf("%d", &n);
        while(n)
        {
            i=dataout();
            hang=i+1;
            switch (n)
            {
            case 1:
                read(i);
                break;
            case 2:
                query(i);
                break;
            case 8:
                user=users();
                break;
            case 9:
                system("cls");
                break;
            default:
                printf("请获得管理员权限\n");
                break;
            }
            if(user==2)
                break;
            menu();
            scanf("%d", &n);
        }
    }
    if(user==2)
    {
        menu();
        scanf("%d", &n);
        while (n)
        {
            i=dataout();
            hang=i+1;
            switch (n)
            {
            case 1:
                read(i);
                break;
            case 2:
                query(i);
                break;
            case 3:
                change(i);
                break;
            case 4:
                sort(i);
                break;
            case 5:
                in(i);
                break;
            case 6:
                out(i);
                break;
            case 7:
                i=clear(i);
                break;
            case 8:
                user=users();
                break;
            case 9:
                system("cls");
                break;
            default:
                printf("输入错误，请输入0~9之间的数字！！！\n");
                break;
            }
            menu();
            scanf("%d", &n);
        }
    }
    return 0;
}

int users()
{
    FILE *fw;
    int n,i=0,j,l=0,k=0;
    char zh[20],password[50];
    printf("普通用户请按1\n管理员用户请按2\n");
    scanf("%d",&n);
    while(n==2)
    {
        printf("\n请输入账号(输入000进入普通用户界面):");
        scanf("%s",&zh);
        if(strcmp(zh,"000")==0)
            return 1;
        printf("请输入密码:");
        password[k] = getch();
        while(password[k]!='\r')
        {
            putchar('*');
            k++;
            password[k] = getch();
        }
        password[k] = '\0';
        printf("\n");
        if ((fw = fopen ("Users.txt", "r")) == NULL)
            printf("不存在管理员用户");
        else
        {
            while(!feof(fw))
            {
                fscanf(fw,"%s %s\n",&Users[i].zh,&Users[i].password);
                i++;
            }
            for(j=0; j<i; j++)
            {
                if(strcmp(Users[j].zh,zh)==0&&strcmp(Users[j].password,password)==0)
                {
                    l++;
                    system("cls");
                    printf("登陆成功!!!\n");
                    return 2;
                }
            }
            if(l==0)
            {
                printf("账号或密码错误");
                continue;
            }
        }
        fclose(fw);
    }
}

void menu()			//菜单函数
{
    system("pause");
    printf("\n\n========================================================================\n");
    printf("------------------------仓库货物信息管理系统设计------------------------\n");
    printf("========================================================================\n\n");
    printf("====================================\n");
    printf("	1:显示功能\n");
    printf("	2:查询功能\n");
    printf("	3:修改功能\n");
    printf("	4:排序功能\n");
    printf("	5:入库功能\n");
    printf("	6:出库功能\n");
    printf("	7:清库功能\n");
    printf("	8:进入管理员模式\n");
    printf("	9:清屏\n");
    printf("	0:退出\n");
    printf("====================================\n");
    printf("请输入0~9之间的整数：");
}

int dataout()		//文件内容存入结构体函数
{
    int i=0;
    FILE* fp;
    if ((fp = fopen ("data.txt", "r")) == NULL)
    {
        sign=0;
    }
    else
    {
        while(!feof(fp))
        {
            fscanf(fp,"%d %s %s %s %s %s %d\n",&goods[i].num,&goods[i].name,&goods[i].category,&goods[i].specifications,&goods[i].manufactor,&goods[i].area,&goods[i].inventory);
            i++;
        }
    }
    fclose(fp);
    return i;
}

void datain(int i)	//内容存入文件函数
{
    int n;
    FILE *fp;
    fp = fopen ("data.txt", "w");
    for(n=0; n<i; n++)
    {
        fprintf(fp,"%d %s %s %s %s %s %d\n",goods[n].num,goods[n].name,goods[n].category,goods[n].specifications,goods[n].manufactor,goods[n].area,goods[n].inventory);
    }
    fclose(fp);
}

void read(int i)	//查看内容函数
{
    if(sign==0)
    {
        printf("====================================\n");
        printf("打开文件失败！！！\n");
        return;
    }
    printf("====================================\n");
    int j;
    printf("行数\t编号\t名称\t类别\t规格\t厂家\t产地\t库存量\n");
    for(j=0; j<i; j++)
    {
        printf("第%d行:\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",j+1,goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
    }
}

void query(int i)	//查询函数
{
    printf("====================================\n");
    printf("------------查询功能界面------------\n");
    printf("====================================\n");
    int j,k,l=0,n;
    int a1;
    char a2[N];
    printf("输入0退出查询功能,输入1开始查询：");
    scanf("%d",&k);
    while(k)
    {
        l=0;
        printf("====================================\n");
        printf("请输入要查询货物的编号或名称或厂家:\n1.编号2.名称或厂家\n");
        scanf("%d",&n);
        if(n==1)
        {
            printf("输入您要查询的货物的编号\n");
            scanf("%d",&a1);
            for(j=0; j<i; j++)
        {
            if(a1==goods[j].num)
            {
                printf("============================================\n");
                printf("编号\t名称\t类别\t规格\t厂家\t产地\t库存量\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
            }
        }
        }

        if(n==2)
        {
            printf("输入您要查询的货物的名称或厂家\n");
            scanf("%s",&a2);
        }
        for(j=0; j<i; j++)
        {
            if(strcmp(a2,goods[j].name)==0||strcmp(a2,goods[j].manufactor)==0)
            {
                printf("============================================\n");
                printf("编号\t名称\t类别\t规格\t厂家\t产地\t库存量\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
            }
        }
        if(l==0)
        {
            printf("====================================\n");
            printf("未查找出你所查询的信息，请重新输入\n");
        }
        printf("====================================\n");
        printf("输入0退出查询功能,输入1开始查询：");
        scanf("%d",&k);
    }
    return;
}

void change(int i)
{
    read(i);
    int x,k;
    char ch[2];
    printf("====================================\n");
    printf("------------修改功能界面------------\n");
    printf("====================================\n");
    printf("输入0退出修改功能,输入1进入修改：");
    scanf("%d",&k);
    while(k)
    {
        printf("====================================\n");
        printf("请输入需要修改的行数：");
        int n,m,a;              //n:修改的行数，a，修改信息类别
        scanf("%d",&n);
        m=n-1;					//m：结构体下标
        while(n)
        {
            printf("====================================\n");
            printf("1.修改编号\n");
            printf("2.修改名称\n");
            printf("3.修改类别\n");
            printf("4.修改规格\n");
            printf("5.修改厂家\n");
            printf("6.修改产地\n");
            printf("7.修改全部选项\n");
            printf("0.退出修改界面\n");
            printf("====================================\n");
            printf("请输入0~7间的整数：");
            scanf("%d",&a);
            printf("====================================\n");
            printf("第%d行:\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",n,goods[m].num,goods[m].name,goods[m].category,goods[m].specifications,goods[m].manufactor,goods[m].area,goods[m].inventory);
            printf("====================================\n");
            switch(a)
            {
            case 1:
                printf("原编号：%d\n",goods[m].num);
                printf("新编号:");
                scanf("%d",&goods[m].num);
                break;
            case 2:
                printf("原名称：%s\n",goods[m].name);
                printf("新名称:");
                scanf("%s",&goods[m].name);
                break;
            case 3:
                printf("原类别：%s\n",goods[m].category);
                printf("新类别:");
                scanf("%s",&goods[m].category);
                break;
            case 4:
                printf("原规格：%s\n",goods[m].specifications);
                printf("新规格:");
                scanf("%s",&goods[m].specifications);
                break;
            case 5:
                printf("原厂家：%s\n",goods[m].manufactor);
                printf("新厂家:");
                scanf("%s",&goods[m].manufactor);
                break;
            case 6:
                printf("原产地：%s\n",goods[m].area);
                printf("新产地:");
                scanf("%s",&goods[m].area);
                break;
            case 7:
                scanf("%d%s%s%s%s%s",&goods[m].num,&goods[m].name,&goods[m].category,&goods[m].specifications,&goods[m].manufactor,&goods[m].area);
                break;
            case 0:
                return;
            default:
                printf("请输入0~7之间的整数：");
                break;
            }
            n=0;
        }
        printf("====================================\n");
        printf("输入0退出修改功能,输入1进入修改：");
        scanf("%d",&k);
    }
    datain(i);
}

void sort(int i)	//排序函数
{
    int n,pass=0,t=0,u,j;
    struct goods trans;
    printf("====================================\n");
    printf("输入您想排序的方式的编号，以回车键结束\n1.编号\n2.类别\n0.退出\n");
    scanf("%d",&n);
    printf("====================================\n");
    if(n==0)
        return;
    if(n==1)
    {
        for(u=0; u<i-1; u++)
        {
            for(j=u; j<i; j++)
            {
                if(goods[u].num>goods[j].num)
                {
                    trans=goods[u];
                    goods[u]=goods[j];
                    goods[j]=trans;
                }
            }
        }
    }
    if(n==2)
    {
        for(u=0; u<i-1; u++)
        {
            for(j=u; j<i; j++)
            {
                if(strcmp(goods[u].category,goods[j].category)>0)
                {
                    trans=goods[u];
                    goods[u]=goods[j];
                    goods[j]=trans;
                }
            }
        }
    }
    for(j=0; j<i; j++)
        printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
    datain(i);
}

int in(int i)		//入库函数
{

    printf("====================================\n");
    printf("------------入库功能界面------------\n");
    printf("====================================\n");
    struct goods newgood;
    int n,j,s=0;
    printf("请输入新货物的基本信息\n");
    printf("编号\t名称\t类别\t规格\t厂家\t产地\t新增库存量\n");
    scanf("%d\t%s\t%s\t%s\t%s\t%s\t%d",&newgood.num,&newgood.name,&newgood.category,&newgood.specifications,&newgood.manufactor,&newgood.area,&newgood.inventory);
    for(j=0; j<i; j++)
    {
        if(newgood.num==goods[j].num)
        {
            goods[j].inventory=goods[j].inventory+newgood.inventory;
            s=1;
            datain(i);
        }
    }
    if(s==0)
    {
        i++;
        goods[i-1]=newgood;
    }
    datain(i);
    return i;
}

void out(int i)
{
    printf("====================================\n");
    printf("------------出库功能界面------------\n");
    printf("====================================\n");
    int j,k,l=0,m=0,n,o;
    // char a[N];
    int a;
    printf("输入0退出出库功能，输入1开始出库：");
    scanf("%d",&k);
    while(k)
    {
        printf("====================================\n");
        printf("请输入要出库货物的编号:");
        scanf("%d",&a);
        for(j=0; j<i; j++)
        {
            if(a==goods[j].num)
            {
                printf("====================================\n");
                printf("编号\t名称\t类别\t规格\t厂家\t产地\t库存量\n");
                printf("%d\t%s\t%s\t%s\t%s\t%s\t%d\n",goods[j].num,goods[j].name,goods[j].category,goods[j].specifications,goods[j].manufactor,goods[j].area,goods[j].inventory);
                l++;
                n=j;
            }
        }
        if(l==0)
        {
            printf("====================================\n");
            printf("未查找出你所查询的信息，请重新输入\n");
        }
        else
        {
            printf("====================================\n");
            printf("请输入需要出库的库存量：");
            scanf("%d",&m);
            goods[n].inventory = goods[n].inventory - m;
            printf("====================================\n");
            printf("剩余库存量：%d\n",goods[n].inventory);
        }
        printf("====================================\n");
        printf("输入0退出出库功能，输入1开始出库：");
        scanf("%d",&k);
    }
    datain(i);
}

int clear(int i)
{

    char a[N];
    int j,k,t,m,n=0,p,q=i,o;
    int num[N];
    printf("====================================\n");
    printf("------------清库功能界面------------\n");
    printf("====================================\n");
    printf("以下显示是库存量为0的货物，请问是否进行下一步操作？\n");
    for(j=0; j<i; j++)
    {
        if(goods[j].inventory==0)
        {
            num[n]=j;
            n++;
        }
    }
    if(n==0)
    {
        printf("没有库存量为0的货物！！！\n");
        return 0;
    }
    else
    {
        printf("====================================\n");
        printf("行数\t编号\t名称\t类别\t规格\t厂家\t产地\t库存量\n");
        for(o=0; o<n; o++)
        {
            printf("第%d行\t%d\t%s\t%s\t%s\t%s\t%s\t%d\n",num[o]+1,goods[num[o]].num,goods[num[o]].name,goods[num[o]].category,goods[num[o]].specifications,goods[num[o]].manufactor,goods[num[o]].area,goods[num[o]].inventory);
        }
    }

    printf("====================================\n");
    printf("输入0退出清库功能，输入1开始清库：");
    scanf("%d",&k);
    while(k)
    {
        for(m=n-1; m>=0; m--)
        {
            for(p=num[m]+1; p<i; p++)
            {
                goods[p-1]=goods[p];
            }
            q--;
        }
        printf("====================================\n");
        printf("输入0退出清库功能,输入1开始清库：");
        scanf("%d",&k);
    }
    datain(q);
    return q;
}
