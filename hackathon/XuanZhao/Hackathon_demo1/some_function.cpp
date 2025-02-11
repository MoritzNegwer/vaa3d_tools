#include "some_function.h"
#include <v3d_interface.h>
#include "Hackathon_demo1_plugin.h"
#include <iostream>
#include <QtGui>
#include <vector>
#include <QList>

inline bool isin(V3DLONG parent,std::vector<V3DLONG> a)
{
    for(int i=0;i<a.size();++i)
    {
        if(parent==a[i])
            return true;
    }
    return false;
}
inline int findIndex(const char* s)
{
    if(s==NULL)
    {
        return -1;
    }
    for(int i=0;;++i)
    {
        if(s[i]=='\0')
            return -2;
        if(s[i]=='.')
            return i;
    }
}
inline QString path(const QString& s)
{
    std::string tmp=s.toStdString();
    const char* tmp0=tmp.c_str();

    int index=findIndex(tmp0);
    const int num=100;
    char tmp1[num];
    for(int i=0;i<index;++i)
    {
        tmp1[i]=tmp0[i];
    }
    tmp1[index]='\0';
    QString result(tmp1);

    return result;

    /*char* tmp1=new char[100];
    strcpy(tmp1,tmp0);
    char* index=strstr(tmp1,'.');
    char s0[index+1];
    for(int i=0;i<index;++i)
    {
        s0[i]=tmp0[i];
    }
    s0[index]='\0';
    QString result(s0);
    return result;*/
}

block getBlockOfOPoint(NeuronSWC p, int dx, int dy, int dz)
{
    std::cout<<"in getBlockOfOPoint"<<endl;
    block btmp;
    btmp.o=p;
    int dd;
    if(p.creatmode==0)
    {
        btmp.min_x=p.x-dx/2;
        btmp.max_x=p.x+dx/2;
        btmp.min_y=p.y-dy/2;
        btmp.max_y=p.y+dy/2;
        btmp.min_z=p.z-dz/2;
        btmp.max_z=p.z+dz/2;
    }
    if(p.creatmode==1)
    {
        dd=5;
        btmp.min_x=p.x-dx/2;
        btmp.max_x=p.x+dx/2;
        btmp.min_y=p.y-dy/2;
        btmp.max_y=p.y+dy/2;
        btmp.min_z=p.z-dd;
        btmp.max_z=p.z+dz-dd;
    }
    if(p.creatmode==2)
    {
        dd=5;
        btmp.min_x=p.x-dx/2;
        btmp.max_x=p.x+dx/2;
        btmp.min_y=p.y-dy/2;
        btmp.max_y=p.y+dy/2;
        btmp.min_z=p.z-dz+dd;
        btmp.max_z=p.z+dd;
    }
    if(p.creatmode==3)
    {
        dd=5;
        btmp.min_x=p.x-dx/2;
        btmp.max_x=p.x+dx/2;
        btmp.min_y=p.y-dy+dd;
        btmp.max_y=p.y+dd;
        btmp.min_z=p.z-dz/2;
        btmp.max_z=p.z+dz/2;
    }
    if(p.creatmode==4)
    {
        dd=5;
        btmp.min_x=p.x-dx/2;
        btmp.max_x=p.x+dx/2;
        btmp.min_y=p.y-dd;
        btmp.max_y=p.y+dy-dd;
        btmp.min_z=p.z-dz/2;
        btmp.max_z=p.z+dz/2;
    }
    if(p.creatmode==5)
    {
        dd=5;
        btmp.min_x=p.x-dd;
        btmp.max_x=p.x+dx-dd;
        btmp.min_y=p.y-dy/2;
        btmp.max_y=p.y+dy/2;
        btmp.min_z=p.z-dz/2;
        btmp.max_z=p.z+dz/2;
    }
    if(p.creatmode==6)
    {
        dd=5;
        btmp.min_x=p.x-dx+dd;
        btmp.max_x=p.x+dd;
        btmp.min_y=p.y-dy/2;
        btmp.max_y=p.y+dy/2;
        btmp.min_z=p.z-dz/2;
        btmp.max_z=p.z+dz/2;
    }
    return btmp;

}

vector<NeuronSWC> getTPointOfBlock(NeuronTree &nt, block b)
{
    std::cout<<"in getTPointOfBlock"<<endl;
    vector<NeuronSWC> tips;
    NeuronSWC ptmp0,ptmp1;
    int size=nt.listNeuron.size();
    std::cout<<"nt size: "<<size<<endl;
    for(int i=0;i<(size-1);++i)
    {
        //std::cout<<i<<endl;
        ptmp0=nt.listNeuron[i];
        ptmp1=nt.listNeuron[i+1];
        if(ptmp1.parent==ptmp0.n
                &&ptmp0.x>b.min_x&&ptmp0.x<=b.max_x
                &&ptmp0.y>b.min_y&&ptmp0.y<=b.max_y
                &&ptmp0.z>b.min_z&&ptmp0.z<=b.max_z)
        {
            //std::cout<<"in if"<<endl;
            if(ptmp1.z>b.max_z
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=2
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=1;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            if(ptmp1.z<b.min_z
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=1
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=2;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            if(ptmp1.y<b.min_y
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=4
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=3;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            if(ptmp1.y>b.max_y
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=3
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=4;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            if(ptmp1.x>b.max_x
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=6
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=5;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            if(ptmp1.x<b.min_x
                    /*&&ptmp1.x>b.min_x&&ptmp1.x<=b.max_x
                    &&ptmp1.y>b.min_y&&ptmp1.y<=b.max_y*/
                    &&b.o.creatmode!=5
                    &&nt.listNeuron[i].on==false)
            {
                ptmp0.creatmode=6;
                tips.push_back(ptmp0);
                std::cout<<"puahback"<<endl;
            }
            nt.listNeuron[i].on=true;
        }
    }
    return tips;
}

blockTree getBlockTree(NeuronTree &nt, int dx, int dy, int dz)
{
    std::cout<<"in getBlockTree"<<endl;
    NeuronSWC o;
    o=nt.listNeuron[0];
    o.creatmode=0;
    NeuronSWC ptmp;
    blockTree bt;
    block btmp;
    vector<NeuronSWC> ptmps,pzs;

    btmp=getBlockOfOPoint(o,dx,dy,dz);
    btmp.n=0;
    btmp.parent=-1;
    ptmps=getTPointOfBlock(nt,btmp);
    std::cout<<"getTPointOfBlock out"<<endl;
    btmp.tips.assign(ptmps.begin(),ptmps.end());
    pzs.insert(pzs.end(),ptmps.begin(),ptmps.end());

    bt.blocklist.push_back(btmp);
    int count=0;
    while(!pzs.empty())
    {
        ptmps.clear();
        ptmp=*(pzs.end()-1);
        pzs.pop_back();
        btmp.tips.clear();
        btmp=getBlockOfOPoint(ptmp,dx,dy,dz);
        btmp.n=bt.blocklist.size();
        for(int i=0;i<bt.blocklist.size();++i)
        {
            for(int j=0;j<bt.blocklist[i].tips.size();++j)
            {
                if(btmp.o.x==bt.blocklist[i].tips[j].x
                        &&btmp.o.y==bt.blocklist[i].tips[j].y
                        &&btmp.o.z==bt.blocklist[i].tips[j].z)
                {
                    btmp.parent=bt.blocklist[i].n;
                }
            }
        }
        ptmps=getTPointOfBlock(nt,btmp);
        btmp.tips.assign(ptmps.begin(),ptmps.end());
        if(ptmps.size()!=0)
        {
            pzs.insert(pzs.end(),ptmps.begin(),ptmps.end());
        }
        bt.blocklist.push_back(btmp);
        std::cout<<pzs.size()<<endl<<count<<endl;
        count++;
    }

    if(pzs.empty())
    {
        std::cout<<"pzs empty"<<endl;
    }

    return bt;

}
