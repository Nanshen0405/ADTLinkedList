/* LinkedList.c -- 使用抽象数据类型（ADT）风格的链表	*/
/* 与list.c一起编译 									*/
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


void OperationOfList(LkList * pList,int choice);	// 实现链表的基本操作 
void ShowInterface(void);							// 进行选择 

int main(int argc,const char * argv[])
{
	LkList list;
	int choice;
	
	// 初始化 
	Sleep(2000); 
	if(List_Initialize(&list) == success) {
		puts("初始化链表成功！"); 
	} else {
		puts("初始化链表失败，没有内存可使用！");
		exit(EXIT_FAILURE);		//	exit_failure 
	}

	// 展示界面并进行操作
	do
	{
		ShowInterface();				// 用于展示界面 
		scanf("%d",&choice);			// 输入操作数 
		
		/* 清屏 */
		system("cls");
		
		// 链表操作实现 
		OperationOfList(&list,choice);
		Sleep(1000); 
		// 当choice不为9时，继续操作 
	} while(choice != 9);
	
	puts("感谢您的使用，欢迎下次使用，再见！！！\n"); 

	return EXIT_SUCCESS;
}


void ShowInterface(void)							// 进行选择
{
//	puts(" \n\n                    \n\n");
	puts("  ******************************************************\n\n");
	puts("  *               ADT链表操作实现系统                  *\n\n");
	puts("  ******************************************************\n\n");
	puts("*********************系统功能菜单*************************\n");
	puts("     ----------------------   ----------------------   	\n");
	puts("     *********************************************     	\n");
	puts("     * 0.系统帮助及说明  * *  1.头插法创建链表   *       	\n");
	puts("     *********************************************     	\n");
	puts("     * 2.尾插法创建链表  * *  3.查找数据的位置   *       	\n");
	puts("     *********************************************     	\n");
	puts("     * 4.查找链表中数据  * *  5.删除某条数据     *       	\n");
	puts("     *********************************************     	\n");
	puts("     * 6.插入某条数据    * *  7.清空链表数据     *		\n");
	puts("     *********************************************     	\n");
	puts("     * 8.遍历链表        * *  9.退出系统         *	 	\n");
	puts("     *********************************************   		\n");
	puts("    ----------------------   ----------------------   	\n");	 
}


void OperationOfList(LkList * pList,int choice)		// 实现链表的基本操作
{
		
	// 初始化 
	int pos,n;
	// 数据元素类型 
	ElemType elem;
	// 初始时，链表的节点数量：
	n = 10; 
	switch(choice)
	{
		case 0:
			puts("输入数字来查看链表的基本操作.\n");
			break; 
		case 1:
			if(List_HeadCreate(pList,n) == success){
				puts("头插法创建链表成功！"); 
			} else {
				puts("头插法创建链表失败！");
				exit(fatal);	//	内存分配失败
			}
//			printf("测试尾指针:\ntail = %d\n",pList->tail->data); 
			break;	
		case 2:
			if(List_TailCreate(pList,n) == success) {
				puts("尾插法创建链表成功！");
			} else {
				puts("尾插法创建链表失败！");
				exit(fatal);	//	内存分配失败
			}
//			printf("测试尾指针:\ntail = %d\n",pList->tail->data);
			break;
		case 3:
			puts("请输入需要查找位置的值：");
			scanf("%d",&elem);
			if(List_Locate(*pList,elem,&pos) == success) {
				printf("找到了,这个值的位置为：%d\n",pos);
			} else {
				puts("查找失败，请检查您的输入是否有误\n");
			}
			break;
		case 4:
			puts("请输入需要查找值的位置：");
			scanf("%d",&pos);
			if (List_Retrieve(*pList,pos,&elem) == success) {
				printf("找到了，这个值为%d\n",elem);
			} else {
				puts("查找失败，请检查您的输入是否有误\n");
			}
			break;
		case 5:
			puts("请输入需要删除的元素和其位置：");
			scanf("%d%d",&elem,&pos);
			if(List_Delete(pList,pos,elem) == success) {
				puts("删除数据成功\n");
			} else {
				puts("删除数据失败，请检查您的输入是否有误！\n");
			}
			break;
		case 6:
			puts("请输入需要插入的元素和位置：");
			scanf("%d%d",&elem,&pos);
			if(List_Insert(pList,pos,elem) == success) {
				puts("插入数据成功\n");
			} else {
				puts("插入数据失败，请检查您的输入是否有误！\n");
			}
			break;
		case 7:
			puts("释放空间.....");
			Sleep(1000);
			if (List_Clear(pList) == success) {
				printf("清空链表成功，链表此时为%s表\n",(List_IsEmpty(*pList)?("空"):("非空")));	
			} else {
				puts("清空链表失败\n");
			}
			break;
		case 8:
			// 遍历输出一遍链表 
			List_Output(*pList);
			break;
		case 9:
		default:
			puts("释放空间.....");
			Sleep(1000);
			if (List_Destory(pList) == success) {
				puts("释放空间成功\n");
			} else {
				puts("释放空间失败\n");
			}
			break;
	}
} 



