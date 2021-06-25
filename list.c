/* list.c -- LinkedList.c文件的接口文件 				*/
/* 与LinkedList.c一起编译 								*/
#include <stdio.h>
#include <stdlib.h>				/* 提供exit()的原型 	*/
#include "list.h"				/* 定义Lklist、Node 	*/

/*
   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
            http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  


                     Mulan Permissive Software License，Version 2

   Mulan Permissive Software License，Version 2 (Mulan PSL v2)
   January 2020 http://license.coscl.org.cn/MulanPSL2

   Your reproduction, use, modification and distribution of the Software shall be subject to Mulan PSL v2 (this License) with the following terms and conditions: 
   
   0. Definition
   
      Software means the program and related documents which are licensed under this License and comprise all Contribution(s). 
   
      Contribution means the copyrightable work licensed by a particular Contributor under this License.
   
      Contributor means the Individual or Legal Entity who licenses its copyrightable work under this License.
   
      Legal Entity means the entity making a Contribution and all its Affiliates.
   
      Affiliates means entities that control, are controlled by, or are under common control with the acting entity under this License, ‘control’ means direct or indirect ownership of at least fifty percent (50%) of the voting power, capital or other securities of controlled or commonly controlled entity.

   1. Grant of Copyright License

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable copyright license to reproduce, use, modify, or distribute its Contribution, with modification or not.

   2. Grant of Patent License 

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable (except for revocation under this Section) patent license to make, have made, use, offer for sale, sell, import or otherwise transfer its Contribution, where such patent license is only limited to the patent claims owned or controlled by such Contributor now or in future which will be necessarily infringed by its Contribution alone, or by combination of the Contribution with the Software to which the Contribution was contributed. The patent license shall not apply to any modification of the Contribution, and any other combination which includes the Contribution. If you or your Affiliates directly or indirectly institute patent litigation (including a cross claim or counterclaim in a litigation) or other patent enforcement activities against any individual or entity by alleging that the Software or any Contribution in it infringes patents, then any patent license granted to you under this License for the Software shall terminate as of the date such litigation or activity is filed or taken.

   3. No Trademark License

      No trademark license is granted to use the trade names, trademarks, service marks, or product names of Contributor, except as required to fulfill notice requirements in Section 4.

   4. Distribution Restriction

      You may distribute the Software in any medium with or without modification, whether in source or executable forms, provided that you provide recipients with a copy of this License and retain copyright, patent, trademark and disclaimer statements in the Software.

   5. Disclaimer of Warranty and Limitation of Liability

      THE SOFTWARE AND CONTRIBUTION IN IT ARE PROVIDED WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED. IN NO EVENT SHALL ANY CONTRIBUTOR OR COPYRIGHT HOLDER BE LIABLE TO YOU FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO ANY DIRECT, OR INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM YOUR USE OR INABILITY TO USE THE SOFTWARE OR THE CONTRIBUTION IN IT, NO MATTER HOW IT’S CAUSED OR BASED ON WHICH LEGAL THEORY, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

   6. Language

      THIS LICENSE IS WRITTEN IN BOTH CHINESE AND ENGLISH, AND THE CHINESE VERSION AND ENGLISH VERSION SHALL HAVE THE SAME LEGAL EFFECT. IN THE CASE OF DIVERGENCE BETWEEN THE CHINESE AND ENGLISH VERSIONS, THE CHINESE VERSION SHALL PREVAIL.

   END OF THE TERMS AND CONDITIONS

   How to Apply the Mulan Permissive Software License，Version 2 (Mulan PSL v2) to Your Software

      To apply the Mulan PSL v2 to your work, for easy identification by recipients, you are suggested to complete following three steps:

      i Fill in the blanks in following statement, including insert your software name, the year of the first publication of your software, and your name identified as the copyright owner; 

      ii Create a file named “LICENSE” which contains the whole context of this License in the first directory of your software package;

      iii Attach the statement to the appropriate annotated syntax at the beginning of each source file.


   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
               http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  
*/

#if 0 
typedef struct _node{			// 链表单节点的结构体 
	ElemType data;				// 单节点中的元素数据  
	struct _node *next;			// 指向下一个节点的指针 
}Node,*NodePtr;					// 节点，节点的指针 

typedef struct _lklist{			// 链式线性表的结构 Linked List 
	Node *head;					// 链表的头结点指针 
	Node *tail;					// 链表的尾结点指针 
}LkList,*LkListPtr;				// 单链表，单链表的指针
#endif

void List_Output(LkList List)
{
	Node *p;
	// 遍历输出链表 
	for(p=List.head->next; p; p=p->next) 
	{
		printf("%d\t",p->data);
	}
	printf("\n");
}
bool List_IsEmpty(LkList List) 								// 判断链表是否为空表
{
	bool flag = true;
	// 判断是否有下一个节点 
	if(List.head->next != NULL) {
		flag = false;
	}
	return flag;
} 
// 创建带头结点和尾结点的空表 
Status List_Initialize(LkList *pList)
{
	
	Status s = success;
	pList->head = pList->tail = NULL;
	Node *p = (Node*)malloc(sizeof(Node));
	 
	if(p){
		// 初始时，链表的下一个节点为空
		// 头结点也为尾结点 
		p->next = NULL;
		pList->head = p;
		pList->tail = p;	
	} else {
		// 内存分配失败
		s = fatal;
	}
	
	return s; 

}
/*
	随机产生n个元素的值，建立带头结点的单链线性表list（头插法） 
*/
Status List_HeadCreate(LkList *pList, int n)	// 从随机数中读入
{
	Status s = success;
	int i;
	// 创建随机数种子 
	srand(time(0));
	// Text Code
	int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
	// 循环插入节点 
	for(i = 0; i < n; i++) 
	{
		// 生成一个新节点 
		Node *p = (Node*)malloc(sizeof(Node));
		if(p) {
			 /**
	         * 1、给新节点赋值 
			 * 2、如果头结点的next为空，表示插入第一个节点
			 * 那么就将尾指针指向这个节点 
			 * 3、将新节点的next指向原头结点的next
	         * 4、将当前节点设置为头结点的next 
	         */
			p->data = a[i];
//			p->data = rand()%100 + 1;
			if(!pList->head->next) {
				pList->tail = p;
			}
			p->next = pList->head->next;
			pList->head->next = p;
		} else {
			// 内存分配失败 
			s = fatal;
			break;
		}
	}

	return s;
}
/*
	随机产生n个元素的值，建立带尾结点的单链线性表list（尾插法） 
*/
Status List_TailCreate(LkList *pList, int n)	// 从随机数中读入
{

	Status s = success;
	int i;
	// 创建随机数种子 
	srand(time(0));
	// Text Code
	int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
	// 循环插入节点 
	for(i = 0; i < n; i++) 
	{
		// 生成一个新节点 
		Node *temp = (Node*)malloc(sizeof(Node));
		if(temp) {
			/*
				1、给新生成的节点赋值
				2、新节点的next为NULL 
				2、尾结点的next指向新节点 
				3、将当前的新节点定义为表尾终端节点 
			*/
			temp->data = a[i];
//			p->data = rand()%100 + 1;
			temp->next = NULL;
			pList->tail->next = temp;
			pList->tail =temp; 
		} else {
			// 内存分配失败 
			s = fatal;
			break;
		}
	}

	return s;
} 


Status List_Retrieve(LkList List, int pos, ElemType *elem) // 按位置查找数据
{
	// 初始化：设置状态变量status，设置移动指针p、计数变量i
	Status s = range_error;
	Node *p =List.head->next;	/* 带头结点，移动p指向第一个元素结点 */
	int i = 1; //计数器
	while(p && i < pos) { 		/* p指向的结点存在，且未到达指定位置 */
		// 条件一防止POS>表长；条件2控制第POS个，防止POS<1
		i++;
		p = p->next;
	}
	if(p && i == pos) { 
		// 找到指定位置，且该结点存在
		*elem = p->data;
		s = success;
	}
	return s;
}
Status List_Locate(LkList List, ElemType elem, int *pos)	// 按值查找位置
{
	/*
		·算法思想描述：
		1、初始化：p指针指向线性表第一个结点；位置i = 1；操作状态s为错误
		2、只要线性表不空，循环做下面的操作
		3、如果待查找数据 == 当前结点数据，则退出循环
		4、否则p指针指向下一个结点；位置计算器i增1
		5、循环外面判断p != NULL，则找到数据，将位置i赋值给pos参数；修改操作状态s为成功；
		6、返回操作状态s
	*/
	Status s = range_error;
	Node *p =List.head->next;
	int i = 1; //计数器
	while(p && p->data != elem) {
//		if(p->data == elem)break;
		i++;
		p = p->next;
	}
	if(p) {
		*pos = i;
		s =success;
	}
	return s;
}

#if 0 
Status List_Retrival(LkList List,int pos, int *p) // 接收参数，返回节点位置
{
	Status s = range_error;
	int i = 1;
	Node *q = pList->head->next;
	/* p指向的结点存在，且未到达指定位置 */
	while(q && i < pos)
	{// 条件一防止POS>表长；条件2控制第POS个，防止POS<1
		i++;
		q = q->next;
	}
	if(p && i == pos){
	// 找到指定位置，且该结点存在
		q = p;
		s = success;
	}
	return s;
}
#endif

Status List_Insert(LkList *pList, int pos, ElemType elem)	// 插入元素
{
	// 移动指针定位   修改指针内容  不移动数据元素
	Status status = fatal;
	Node *p,*q,*s;
	int i;
	for(p=pList->head->next,q = NULL,i = 1; p ; q=p,p=p->next,i++) 
	{
		if(pos == i) {
			s = (Node*)malloc(sizeof(Node));
			s->data = elem;
			if(s && q) {
				s->next = q->next;
				q->next = s;
			} else if(q == NULL) {
				s->next = pList->head;
				pList->head = s;
			}
			status = success;
			break;
		}
	}
	return status;
}


Status List_Delete(LkList *pList, int pos,ElemType elem)	// 删除元素
{
	// 移动指针定位	修改指针内容	不移动数据元素
	Status status = fail;
	Node *p,*q;
	int i;
	for(q=NULL,p=pList->head->next,i = 1; p; q=p,p=p->next,i++) 
	{
		if(p->data == elem && pos == i) {
			if(q) {
				q->next=p->next;
			} else {
				pList->head= p->next;
			}
			free(p);
			status = success;
			break;
		}
	}
	return status;

}
Status List_Destory(LkList *pList)	//	销毁整个线性表
{
	Node *p,*q;
	/*
		p指向第一个节点，如果p没到表尾 
		就继续循环体，释放下一个节点 
	*/ 	
	p = pList->head;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	return success;
}
Status List_Clear(LkList *pList)								// 清空线性表
{
	Node *p,*q;
	/*
		p指向第一个节点，如果p没到表尾 
		就继续循环体，释放下一个节点 
	*/ 	
	p = pList->head->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pList->head->next = NULL;	// 头结点指针域设置为空 
	
	return success;
} 

