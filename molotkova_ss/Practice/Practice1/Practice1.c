#include <stdio.h> 
#include <math.h> 
#include <locale.h> 

void main()
{ 
    float dsp, dvp, der; // ���,���,��������� ������ � �3
	float h, w, d; // �������� ������������� ������: ������, ������, �������
	float mz, mb, mk, md, mp, m;//�����
	float t1, t2, t3, t4;// �������
	t1=0.005;
	t2=0.015;
	t3=0.015;
	t4=0.01;
    setlocale(LC_ALL, "Russian"); 

    printf("������� ������ � ������\n"); 
	scanf("%f", &h); 
	printf("������� ������\n"); 
	scanf("%f", &w); 
	printf("������� �������\n"); 
    scanf("%f", &d); 
	printf("������� ���\n"); 
	scanf("%f", &dsp); 
	printf("������� ���\n"); 
	scanf("%f", &dvp); 
	printf("������� ��������� ������\n"); 
	scanf("%f", &der); 
if ((1.8<h)&&(h<2.2)&&(0.8<w)&&(w<1.2)&&(0.5<d)&&(d<0.9))
	{
		mz=h*w*t1*dvp;
		mb=2*h*d*t2*dsp;
		mk=2*dsp*w*d*t3;
		md=h*w*t4*der;
		mp=dsp*((int)((h - 2 * 0.015) / (0.4 + 0.015))) * (w - 2 * 0.015) * (d - 0.005);
		m= (mz+mb+mk+md+mp)/100;
		
		printf("����� ����� %0.f ��\n",m);
	}
	else printf("��������� �������� �� ������������� �������");
}
