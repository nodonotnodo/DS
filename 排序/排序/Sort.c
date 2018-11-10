#include "Sort.h"

//��������
void InsertSort(datatype *data, int size)
{
	int insert = 1;
	assert(data != NULL);
	//������������ֻ��һ�����ݣ���ô�Ѿ����򣬲����ٽ�������
	if (size == 1){
		return;
	}
	for (; insert < size; insert++){//insert-size-1�����ݶ�������ģ���Ҫ����������
		//�ҵ�data[insert]Ӧ�ò��뵽��������λ��
		int left = 0;
		int right = insert-1;
		while (left < right){
			int mid = left + (right - left) / 2;
			if (data[mid] <= data[insert]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		
		int tmp = data[insert];
		if (tmp >= data[left]){//�ж�data��Ҫ����λ�����ݵĴ�С��ϵ��Ϊ��֤�ȶ��ԣ�data���ڵ���ʱ������λ�ú��档
			for (int i = insert; i > left+1; i--){
				data[i] = data[i - 1];
			}
			data[left + 1] = tmp;
		}
		else{//dataС��ʱ������λ��ǰ��
			for (int i = insert; i > left; i--){
				data[i] = data[i - 1];
			}
			data[left] = tmp;
		}
	}
}

//ϣ������
/*
ϣ��������ʵ���ǲ��������������
���Ƿ��֣���������ĺ�ʱ�������ݵ�����̶��ǳɷ��ȵġ�
�������ǿ����ڲ���֮ǰ�����ݽ��д���ʹ������̶����ӣ������ϣ������
	������š�
*/
void ShellSort(datatype *data, int size)
{
	assert(data != NULL);
	for (int i = 0; i < 3; i++){
		//������������ֻ��һ�����ݣ���ô�Ѿ����򣬲����ٽ�������
		for (int insert = i+3; insert < size; insert+=3){//insert-size-1�����ݶ�������ģ���Ҫ����������
			//�ҵ�data[insert]Ӧ�ò��뵽��������λ��
			int left = i;
			int right = insert - 3;
			while (left < right){
				int mid = (left/3 + (right/3 - left/3) / 2)*3+i;
				if (data[mid] <= data[insert]){
					left = mid + 3;
				}
				else{
					right = mid - 3;
				}
			}

			int tmp = data[insert];
			if (tmp >= data[left]){//�ж�data��Ҫ����λ�����ݵĴ�С��ϵ��Ϊ��֤�ȶ��ԣ�data���ڵ���ʱ������λ�ú��档
				for (int i = insert; i > left + 3; i-=3){
					data[i] = data[i - 3];
				}
				data[left + 3] = tmp;
			}
			else{//dataС��ʱ������λ��ǰ��
				for (int i = insert; i > left; i-=3){
					data[i] = data[i - -3];
				}
				data[left] = tmp;
			}
		}
	}
	InsertSort(data, size);
}