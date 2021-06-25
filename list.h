/* list.h -- ���������͵�ͷ�ļ� 					*/
/* ��list.c��LinkedList.cһ����� 					*/
#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>			/* C99����			*/
#include <windows.h>			/* windows������	*/

/*
   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
            http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  


                     Mulan Permissive Software License��Version 2

   Mulan Permissive Software License��Version 2 (Mulan PSL v2)
   January 2020 http://license.coscl.org.cn/MulanPSL2

   Your reproduction, use, modification and distribution of the Software shall be subject to Mulan PSL v2 (this License) with the following terms and conditions: 
   
   0. Definition
   
      Software means the program and related documents which are licensed under this License and comprise all Contribution(s). 
   
      Contribution means the copyrightable work licensed by a particular Contributor under this License.
   
      Contributor means the Individual or Legal Entity who licenses its copyrightable work under this License.
   
      Legal Entity means the entity making a Contribution and all its Affiliates.
   
      Affiliates means entities that control, are controlled by, or are under common control with the acting entity under this License, ��control�� means direct or indirect ownership of at least fifty percent (50%) of the voting power, capital or other securities of controlled or commonly controlled entity.

   1. Grant of Copyright License

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable copyright license to reproduce, use, modify, or distribute its Contribution, with modification or not.

   2. Grant of Patent License 

      Subject to the terms and conditions of this License, each Contributor hereby grants to you a perpetual, worldwide, royalty-free, non-exclusive, irrevocable (except for revocation under this Section) patent license to make, have made, use, offer for sale, sell, import or otherwise transfer its Contribution, where such patent license is only limited to the patent claims owned or controlled by such Contributor now or in future which will be necessarily infringed by its Contribution alone, or by combination of the Contribution with the Software to which the Contribution was contributed. The patent license shall not apply to any modification of the Contribution, and any other combination which includes the Contribution. If you or your Affiliates directly or indirectly institute patent litigation (including a cross claim or counterclaim in a litigation) or other patent enforcement activities against any individual or entity by alleging that the Software or any Contribution in it infringes patents, then any patent license granted to you under this License for the Software shall terminate as of the date such litigation or activity is filed or taken.

   3. No Trademark License

      No trademark license is granted to use the trade names, trademarks, service marks, or product names of Contributor, except as required to fulfill notice requirements in Section 4.

   4. Distribution Restriction

      You may distribute the Software in any medium with or without modification, whether in source or executable forms, provided that you provide recipients with a copy of this License and retain copyright, patent, trademark and disclaimer statements in the Software.

   5. Disclaimer of Warranty and Limitation of Liability

      THE SOFTWARE AND CONTRIBUTION IN IT ARE PROVIDED WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED. IN NO EVENT SHALL ANY CONTRIBUTOR OR COPYRIGHT HOLDER BE LIABLE TO YOU FOR ANY DAMAGES, INCLUDING, BUT NOT LIMITED TO ANY DIRECT, OR INDIRECT, SPECIAL OR CONSEQUENTIAL DAMAGES ARISING FROM YOUR USE OR INABILITY TO USE THE SOFTWARE OR THE CONTRIBUTION IN IT, NO MATTER HOW IT��S CAUSED OR BASED ON WHICH LEGAL THEORY, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.

   6. Language

      THIS LICENSE IS WRITTEN IN BOTH CHINESE AND ENGLISH, AND THE CHINESE VERSION AND ENGLISH VERSION SHALL HAVE THE SAME LEGAL EFFECT. IN THE CASE OF DIVERGENCE BETWEEN THE CHINESE AND ENGLISH VERSIONS, THE CHINESE VERSION SHALL PREVAIL.

   END OF THE TERMS AND CONDITIONS

   How to Apply the Mulan Permissive Software License��Version 2 (Mulan PSL v2) to Your Software

      To apply the Mulan PSL v2 to your work, for easy identification by recipients, you are suggested to complete following three steps:

      i Fill in the blanks in following statement, including insert your software name, the year of the first publication of your software, and your name identified as the copyright owner; 

      ii Create a file named ��LICENSE�� which contains the whole context of this License in the first directory of your software package;

      iii Attach the statement to the appropriate annotated syntax at the beginning of each source file.


   Copyright (c) [Year] [name of copyright holder]
   [Software Name] is licensed under Mulan PSL v2.
   You can use this software according to the terms and conditions of the Mulan PSL v2. 
   You may obtain a copy of Mulan PSL v2 at:
               http://license.coscl.org.cn/MulanPSL2 
   THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT, MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.  
   See the Mulan PSL v2 for more details.  
*/

typedef int ElemType;			// Ԥ�������Ԫ������ 
typedef int Status; 			// �������״̬����ֵ 


enum Status{
	success = 1, fail = 0, 
	/*�ڴ����ʧ��*/
	fatal = -1, 
	/*�����ռ����Խ��*/
	range_error = -2 
};

typedef struct _node{			// �����ڵ�Ľṹ�� 
	ElemType data;				// ���ڵ��е�Ԫ������  
	struct _node *next;			// ָ����һ���ڵ��ָ�� 
}Node,*NodePtr;					// �ڵ㣬�ڵ��ָ�� 

typedef struct _lklist{			// ��ʽ���Ա�Ľṹ Linked List 
	Node *head;					// �����ͷ���ָ�� 
	Node *tail;					// �����β���ָ�� 
}LkList,*LkListPtr;				// �������������ָ��

/* ����ԭ�� */


/* ��������ʼ��һ������ 												*/
/* ǰ��������pListָ��һ������											*/
/* ���������������ʼ��Ϊ�� 											*/
Status List_Initialize(LkList *pList);							// ��ʼ������һ���ձ�

/* ������ͷ�巨����һ������ 											*/
/* ǰ��������pListָ��һ����������n��Ԫ�ؽڵ� 						*/
/* �����������������ɹ� 												*/
Status List_HeadCreate(LkList *pList, int n);					// ��������ж��룬ͷ�巨

/* ������ͷ�巨����һ������ 											*/
/* ǰ��������pListָ��һ����������n��Ԫ�ؽڵ� 						*/
/* �����������������ɹ� 												*/
Status List_TailCreate(LkList *pList, int n);					// ��������ж��� ��β�巨 

/* �������������ÿ���ڵ� 												*/
/* ����������List��һ�����������������ÿ���ڵ��ϵ���� 			*/
bool List_IsEmpty(LkList List); 								// �ж������Ƿ�Ϊ�ձ� 

// void List_Input(LkList *pList,int number);					// �ֶ���������

/* ������ȷ�������Ƿ�Ϊ�ն��壬List��һ���ѳ�ʼ��������				    */
/* �����������������Ϊ�գ��ú�������true�����򷵻�false 				*/ 
void List_Output(LkList List);			 						// ������� 

// Status List_Retrival(SqListPtr List,int pos, Node *p); 		// ���ղ��������ؽڵ�λ��

/* ���������������е�Ԫ�� 												*/
/* ǰ��������List��һ������pos��ʾԪ��λ�ã�elemָ��һ��Ԫ�� 			*/
/* ������������������ָ��λ�õ�Ԫ�أ�����ָ�뷵����Ԫ��ֵ 				*/
Status List_Retrieve(LkList List, int pos, ElemType *elem);		// ��λ�ò���Ԫ��

/* ����������ָ��Ԫ�ص�λ�� 											*/
/* ǰ��������List��һ������elem��һ��Ԫ�أ�pos��ʾָ����һ��λ�� 		*/
/* ������������������ָ��Ԫ�ص�λ�ã�����ָ�뷵����λ�� 				*/
Status List_Locate(LkList List, ElemType elem, int *pos);		// ��Ԫ�ز���λ��

/* �������������в���һ���ڵ� 											*/
/* ǰ��������pListָ��һ������pos��ʾԪ�ز���λ�ã�elemָ����Ԫ�ر��� */
/* �����������������е�ָ��λ�ò���һ��ָ��Ԫ�صĽڵ� 					*/
Status List_Insert(LkList *pList, int pos, ElemType elem);		// ����Ԫ��

/* ������ɾ�������е�һ���ڵ� 											*/
/* ǰ��������pListָ��һ������pos��ʾԪ��ɾ��λ�ã�elemָɾ��Ԫ�ر��� */
/* ����������ɾ�������е�ָ��λ�õ�Ԫ�صĽڵ� 							*/
Status List_Delete(LkList *pList, int pos,ElemType elem);		// ɾ��Ԫ��

/* �������ͷ��ѷ�����ڴ棬�������Ա�������еĻ��� 				*/
/* ǰ��������pListָ��һ������ 											*/
/* �����������ͷ���Ϊ�����������пռ䣬����������Ŀռ�				*/
Status List_Destory(LkList *pList); 		 					// �����������Ա�

/* �������ͷ��ѷ�����ڴ棨����еĻ���									*/
/* ǰ��������pListָ��һ������ 											*/
/* �����������ͷ���Ϊ�����������пռ䣬��������Ϊ�� 					*/
Status List_Clear(LkList *pList);								// ������Ա� 

#endif 
