/* list.h -- 单链表类型的头文件 					*/
/* 与list.c、LinkedList.c一起编译 					*/
#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>			/* C99特性			*/
#include <windows.h>			/* windows函数库	*/

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

typedef int ElemType;			// 预设的数据元素类型 
typedef int Status; 			// 函数结果状态返回值 


enum Status{
	success = 1, fail = 0, 
	/*内存分配失败*/
	fatal = -1, 
	/*连续空间访问越界*/
	range_error = -2 
};

typedef struct _node{			// 链表单节点的结构体 
	ElemType data;				// 单节点中的元素数据  
	struct _node *next;			// 指向下一个节点的指针 
}Node,*NodePtr;					// 节点，节点的指针 

typedef struct _lklist{			// 链式线性表的结构 Linked List 
	Node *head;					// 链表的头结点指针 
	Node *tail;					// 链表的尾结点指针 
}LkList,*LkListPtr;				// 单链表，单链表的指针

/* 函数原型 */


/* 操作：初始化一个链表 												*/
/* 前置条件：pList指向一个链表											*/
/* 后置条件：链表初始化为空 											*/
Status List_Initialize(LkList *pList);							// 初始化创建一个空表

/* 操作：头插法创建一个链表 											*/
/* 前置条件：pList指向一个链表，创建n个元素节点 						*/
/* 后置条件：链表创建成功 												*/
Status List_HeadCreate(LkList *pList, int n);					// 从随机数中读入，头插法

/* 操作：头插法创建一个链表 											*/
/* 前置条件：pList指向一个链表，创建n个元素节点 						*/
/* 后置条件：链表创建成功 												*/
Status List_TailCreate(LkList *pList, int n);					// 从随机数中读入 ，尾插法 

/* 操作：输出链表每个节点 												*/
/* 后置条件：List是一个链表，遍历链表，输出每个节点上的输出 			*/
bool List_IsEmpty(LkList List); 								// 判断链表是否为空表 

// void List_Input(LkList *pList,int number);					// 手动输入数据

/* 操作：确定链表是否为空定义，List是一个已初始化的链表				    */
/* 后置条件：如果链表为空，该函数返回true；否则返回false 				*/ 
void List_Output(LkList List);			 						// 输出数据 

// Status List_Retrival(SqListPtr List,int pos, Node *p); 		// 接收参数，返回节点位置

/* 操作：查找链表中的元素 												*/
/* 前置条件：List是一个链表，pos表示元素位置，elem指向一个元素 			*/
/* 后置条件：查找链表指定位置的元素，利用指针返回其元素值 				*/
Status List_Retrieve(LkList List, int pos, ElemType *elem);		// 按位置查找元素

/* 操作：查找指定元素的位置 											*/
/* 前置条件：List是一个链表，elem是一个元素，pos表示指定的一个位置 		*/
/* 后置条件：查找链表指定元素的位置，利用指针返回其位置 				*/
Status List_Locate(LkList List, ElemType elem, int *pos);		// 按元素查找位置

/* 操作：往链表中插入一个节点 											*/
/* 前置条件：pList指向一个链表，pos表示元素插入位置，elem指插入元素本身 */
/* 后置条件：向链表中的指定位置插入一个指定元素的节点 					*/
Status List_Insert(LkList *pList, int pos, ElemType elem);		// 插入元素

/* 操作：删除链表中的一个节点 											*/
/* 前置条件：pList指向一个链表，pos表示元素删除位置，elem指删除元素本身 */
/* 后置条件：删除链表中的指定位置的元素的节点 							*/
Status List_Delete(LkList *pList, int pos,ElemType elem);		// 删除元素

/* 操作：释放已分配的内存，包括线性表本身（如果有的话） 				*/
/* 前置条件：pList指向一个链表 											*/
/* 后置条件：释放了为链表分配的所有空间，包括链表本身的空间				*/
Status List_Destory(LkList *pList); 		 					// 销毁整个线性表

/* 操作：释放已分配的内存（如果有的话）									*/
/* 前置条件：pList指向一个链表 											*/
/* 后置条件：释放了为链表分配的所有空间，链表设置为空 					*/
Status List_Clear(LkList *pList);								// 清空线性表 

#endif 
