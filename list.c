/* list.c -- LinkedList.c�ļ��Ľӿ��ļ� 				*/
/* ��LinkedList.cһ����� 								*/
#include <stdio.h>
#include <stdlib.h>				/* �ṩexit()��ԭ�� 	*/
#include "list.h"				/* ����Lklist��Node 	*/

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

#if 0 
typedef struct _node{			// �����ڵ�Ľṹ�� 
	ElemType data;				// ���ڵ��е�Ԫ������  
	struct _node *next;			// ָ����һ���ڵ��ָ�� 
}Node,*NodePtr;					// �ڵ㣬�ڵ��ָ�� 

typedef struct _lklist{			// ��ʽ���Ա�Ľṹ Linked List 
	Node *head;					// �����ͷ���ָ�� 
	Node *tail;					// �����β���ָ�� 
}LkList,*LkListPtr;				// �������������ָ��
#endif

void List_Output(LkList List)
{
	Node *p;
	// ����������� 
	for(p=List.head->next; p; p=p->next) 
	{
		printf("%d\t",p->data);
	}
	printf("\n");
}
bool List_IsEmpty(LkList List) 								// �ж������Ƿ�Ϊ�ձ�
{
	bool flag = true;
	// �ж��Ƿ�����һ���ڵ� 
	if(List.head->next != NULL) {
		flag = false;
	}
	return flag;
} 
// ������ͷ����β���Ŀձ� 
Status List_Initialize(LkList *pList)
{
	
	Status s = success;
	pList->head = pList->tail = NULL;
	Node *p = (Node*)malloc(sizeof(Node));
	 
	if(p){
		// ��ʼʱ���������һ���ڵ�Ϊ��
		// ͷ���ҲΪβ��� 
		p->next = NULL;
		pList->head = p;
		pList->tail = p;	
	} else {
		// �ڴ����ʧ��
		s = fatal;
	}
	
	return s; 

}
/*
	�������n��Ԫ�ص�ֵ��������ͷ���ĵ������Ա�list��ͷ�巨�� 
*/
Status List_HeadCreate(LkList *pList, int n)	// ��������ж���
{
	Status s = success;
	int i;
	// ������������� 
	srand(time(0));
	// Text Code
	int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
	// ѭ������ڵ� 
	for(i = 0; i < n; i++) 
	{
		// ����һ���½ڵ� 
		Node *p = (Node*)malloc(sizeof(Node));
		if(p) {
			 /**
	         * 1�����½ڵ㸳ֵ 
			 * 2�����ͷ����nextΪ�գ���ʾ�����һ���ڵ�
			 * ��ô�ͽ�βָ��ָ������ڵ� 
			 * 3�����½ڵ��nextָ��ԭͷ����next
	         * 4������ǰ�ڵ�����Ϊͷ����next 
	         */
			p->data = a[i];
//			p->data = rand()%100 + 1;
			if(!pList->head->next) {
				pList->tail = p;
			}
			p->next = pList->head->next;
			pList->head->next = p;
		} else {
			// �ڴ����ʧ�� 
			s = fatal;
			break;
		}
	}

	return s;
}
/*
	�������n��Ԫ�ص�ֵ��������β���ĵ������Ա�list��β�巨�� 
*/
Status List_TailCreate(LkList *pList, int n)	// ��������ж���
{

	Status s = success;
	int i;
	// ������������� 
	srand(time(0));
	// Text Code
	int a[10] = {1,2,3,4,5,6,7,8,9,10}; 
	// ѭ������ڵ� 
	for(i = 0; i < n; i++) 
	{
		// ����һ���½ڵ� 
		Node *temp = (Node*)malloc(sizeof(Node));
		if(temp) {
			/*
				1���������ɵĽڵ㸳ֵ
				2���½ڵ��nextΪNULL 
				2��β����nextָ���½ڵ� 
				3������ǰ���½ڵ㶨��Ϊ��β�ն˽ڵ� 
			*/
			temp->data = a[i];
//			p->data = rand()%100 + 1;
			temp->next = NULL;
			pList->tail->next = temp;
			pList->tail =temp; 
		} else {
			// �ڴ����ʧ�� 
			s = fatal;
			break;
		}
	}

	return s;
} 


Status List_Retrieve(LkList List, int pos, ElemType *elem) // ��λ�ò�������
{
	// ��ʼ��������״̬����status�������ƶ�ָ��p����������i
	Status s = range_error;
	Node *p =List.head->next;	/* ��ͷ��㣬�ƶ�pָ���һ��Ԫ�ؽ�� */
	int i = 1; //������
	while(p && i < pos) { 		/* pָ��Ľ����ڣ���δ����ָ��λ�� */
		// ����һ��ֹPOS>��������2���Ƶ�POS������ֹPOS<1
		i++;
		p = p->next;
	}
	if(p && i == pos) { 
		// �ҵ�ָ��λ�ã��Ҹý�����
		*elem = p->data;
		s = success;
	}
	return s;
}
Status List_Locate(LkList List, ElemType elem, int *pos)	// ��ֵ����λ��
{
	/*
		���㷨˼��������
		1����ʼ����pָ��ָ�����Ա��һ����㣻λ��i = 1������״̬sΪ����
		2��ֻҪ���Ա��գ�ѭ��������Ĳ���
		3��������������� == ��ǰ������ݣ����˳�ѭ��
		4������pָ��ָ����һ����㣻λ�ü�����i��1
		5��ѭ�������ж�p != NULL�����ҵ����ݣ���λ��i��ֵ��pos�������޸Ĳ���״̬sΪ�ɹ���
		6�����ز���״̬s
	*/
	Status s = range_error;
	Node *p =List.head->next;
	int i = 1; //������
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
Status List_Retrival(LkList List,int pos, int *p) // ���ղ��������ؽڵ�λ��
{
	Status s = range_error;
	int i = 1;
	Node *q = pList->head->next;
	/* pָ��Ľ����ڣ���δ����ָ��λ�� */
	while(q && i < pos)
	{// ����һ��ֹPOS>��������2���Ƶ�POS������ֹPOS<1
		i++;
		q = q->next;
	}
	if(p && i == pos){
	// �ҵ�ָ��λ�ã��Ҹý�����
		q = p;
		s = success;
	}
	return s;
}
#endif

Status List_Insert(LkList *pList, int pos, ElemType elem)	// ����Ԫ��
{
	// �ƶ�ָ�붨λ   �޸�ָ������  ���ƶ�����Ԫ��
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


Status List_Delete(LkList *pList, int pos,ElemType elem)	// ɾ��Ԫ��
{
	// �ƶ�ָ�붨λ	�޸�ָ������	���ƶ�����Ԫ��
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
Status List_Destory(LkList *pList)	//	�����������Ա�
{
	Node *p,*q;
	/*
		pָ���һ���ڵ㣬���pû����β 
		�ͼ���ѭ���壬�ͷ���һ���ڵ� 
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
Status List_Clear(LkList *pList)								// ������Ա�
{
	Node *p,*q;
	/*
		pָ���һ���ڵ㣬���pû����β 
		�ͼ���ѭ���壬�ͷ���һ���ڵ� 
	*/ 	
	p = pList->head->next;
	while(p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	pList->head->next = NULL;	// ͷ���ָ��������Ϊ�� 
	
	return success;
} 

