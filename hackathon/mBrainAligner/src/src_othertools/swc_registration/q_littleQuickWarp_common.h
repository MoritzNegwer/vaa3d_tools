//q_littleQuickWarp_common.h
//by wt
//2019.10.16

#ifndef __Q_LITTLEQUICKWARP_COMMON_H__
#define __Q_LITTLEQUICKWARP_COMMON_H__

#include "stackutil.h"
typedef unsigned char UINT8_JBA;
typedef float MYFLOAT_JBA;

class Coord3D_JBA
{
public:
	MYFLOAT_JBA x, y, z;
	Coord3D_JBA(float x0, float y0, float z0) { x = x0; y = y0; z = z0; }
	Coord3D_JBA() { x = y = z = 0; }
};

class Size3D
{
public:
	V3DLONG sz0, sz1, sz2;
	Size3D() { sz0 = sz1 = sz2 = 0; }
	Size3D(V3DLONG s0, V3DLONG s1, V3DLONG s2) { sz0 = s0; sz1 = s1; sz2 = s2; }
	Size3D(V3DLONG *s, V3DLONG len = 3) { sz0 = sz1 = sz2 = 0; if (len >= 1) sz0 = s[0]; if (len >= 2) sz1 = s[1]; if (len >= 3) sz2 = s[2]; }
	~Size3D() { sz0 = sz1 = sz2 = 0; }
	bool valid() { return (sz0>0 && sz1>0 && sz2>0) ? true : false; }
};

class Size2D
{
public:
	V3DLONG sz0, sz1;
	Size2D() { sz0 = sz1 = 0; }
	Size2D(V3DLONG s0, V3DLONG s1) { sz0 = s0; sz1 = s1; }
	Size2D(V3DLONG *s, V3DLONG len = 2) { sz0 = sz1 = 0; if (len >= 1) sz0 = s[0]; if (len >= 2) sz1 = s[1]; }
	~Size2D() { sz0 = sz1 = 0; }
	bool valid() { return (sz0>0 && sz1>0) ? true : false; }
};

class DisplaceFieldF3D
{
public:
	UINT8_JBA b_transform;

	MYFLOAT_JBA sx, sy, sz; //shift of x,y,z
	DisplaceFieldF3D() { sx = sy = sz = 0; b_transform = 0; }
	DisplaceFieldF3D(double vv) { sx = sy = sz = vv; b_transform = 0; }
	void scale(double dfactor) { sx *= dfactor; sy *= dfactor; sz *= dfactor; }
	void resetToDefault() //070517
	{
		sx = 0; sy = 0; sz = 0;
		b_transform = 0;
	}
	bool copy(DisplaceFieldF3D *wp)
	{
		if (!wp) return false;
		sx = wp->sx;  sy = wp->sy;  sz = wp->sz;
		b_transform = wp->b_transform;
		return true;
	}
	bool copy(DisplaceFieldF3D &wp)
	{
		sx = wp.sx;  sy = wp.sy;  sz = wp.sz;
		b_transform = wp.b_transform;
		return true;
	}

};

template <class T> class Vol3DSimple
{
private:
	Size3D sz;
	V3DLONG len;
	T * data1d;
	T *** data3d;

	bool allocateMemory(V3DLONG s0, V3DLONG s1, V3DLONG s2)
	{
		V3DLONG tmplen = s0*s1*s2;
		if (tmplen>0 && s0>0 && s1>0 && s2>0)
		{
			data1d = new T[tmplen];
			if (data1d)
			{
				data3d = 0;
				new3dpointer(data3d, s0, s1, s2, data1d);
				if (data3d)
				{
					sz.sz0 = s0;
					sz.sz1 = s1;
					sz.sz2 = s2;
					len = tmplen;
					return true;
				}
				else
				{
					if (data1d) { delete[]data1d; data1d = 0; }
					sz.sz0 = sz.sz1 = sz.sz2 = len = 0;
					return false;
				}
			}
			else
			{
				sz.sz0 = sz.sz1 = sz.sz2 = len = 0;
				data1d = 0;
				data3d = 0;
				return false;
			}
		}
		else
		{
			sz.sz0 = sz.sz1 = sz.sz2 = len = 0;
			data1d = 0;
			data3d = 0;
			return false;
		}
	}

public:
	Vol3DSimple() { sz.sz0 = sz.sz1 = sz.sz2 = len = 0; data1d = 0; data3d = 0; }
	Vol3DSimple(V3DLONG s0, V3DLONG s1, V3DLONG s2)
	{
		allocateMemory(s0, s1, s2);
	}
	template <class T1> Vol3DSimple(Vol3DSimple <T1> * vsubject, V3DLONG xb, V3DLONG xe, V3DLONG yb, V3DLONG ye, V3DLONG zb, V3DLONG ze)
	{
		//check the validity of data
		V3DLONG vsz0 = vsubject->sz0(), vsz1 = vsubject->sz1(), vsz2 = vsubject->sz2();
		if (!vsubject->valid() || vsz0 <= 0 || vsz1 <= 0 || vsz2 <= 0) { fprintf(stderr, "Invalid parameter.\n"); return; } //do nothing
		if (xb>xe) { V3DLONG tmp; tmp = xb; xb = xe; xe = tmp; } //swapValue(xb, xe);
		if (yb>ye) { V3DLONG tmp; tmp = yb; yb = ye; ye = tmp; } //swapValue(yb, ye);
		if (zb>ze) { V3DLONG tmp; tmp = zb; zb = ze; ze = tmp; } //swapValue(zb, ze);
		if ((xb<0 && xe<0) || (xb >= vsz0 && xe >= vsz0)) { fprintf(stderr, "Invalid parameter.\n"); return; }
		if ((yb<0 && ye<0) || (yb >= vsz1 && ye >= vsz1)) { fprintf(stderr, "Invalid parameter.\n"); return; }
		if ((zb<0 && ze<0) || (zb >= vsz2 && ze >= vsz2)) { fprintf(stderr, "Invalid parameter.\n"); return; }

		if (xb<0) xb = 0; if (xb >= vsz0) xb = vsz0 - 1;
		if (xe<0) xe = 0; if (xe >= vsz0) xe = vsz0 - 1;
		if (yb<0) yb = 0; if (yb >= vsz1) yb = vsz1 - 1;
		if (ye<0) ye = 0; if (ye >= vsz1) ye = vsz1 - 1;
		if (zb<0) zb = 0; if (zb >= vsz2) zb = vsz2 - 1;
		if (ze<0) ze = 0; if (ze >= vsz2) ze = vsz2 - 1;

		//allocate memory
		if (!allocateMemory(xe - xb + 1, ye - yb + 1, ze - zb + 1)) { fprintf(stderr, "Fail to allocate mmeory in initialize Vol3DSimple().\n"); return; }

		//copy data
		T1 *** vsubject_ref = vsubject->getData3dHandle();
		V3DLONG i, j, k, i0, j0, k0;
		for (k = zb, k0 = 0; k <= ze; k++, k0++)
		{
			for (j = yb, j0 = 0; j <= ye; j++, j0++)
			{
				for (i = xb, i0 = 0; i <= xe; i++, i0++)
				{
					data3d[k0][j0][i0] = (T)(vsubject_ref[k][j][i]);
				}
			}
		}

		return;
	}
	template <class T1> Vol3DSimple(Vol3DSimple <T1> * vsubject)
	{
		//check the validity of data
		if (!vsubject->valid()) { fprintf(stderr, "Invalid parameter.\n"); return; } //do nothing
		V3DLONG vsz0 = vsubject->sz0(), vsz1 = vsubject->sz1(), vsz2 = vsubject->sz2();

		//allocate memory
		if (!allocateMemory(vsz0, vsz1, vsz2)) { fprintf(stderr, "Fail to allocate mmeory in initialize Vol3DSimple().\n"); return; }

		//copy data
		T1 *** vsubject_ref = vsubject->getData3dHandle();
		V3DLONG i0, j0, k0;
		for (k0 = 0; k0<vsz2; k0++)
		{
			for (j0 = 0; j0<vsz1; j0++)
			{
				for (i0 = 0; i0<vsz0; i0++)
				{
					data3d[k0][j0][i0] = (T)(vsubject_ref[k0][j0][i0]);
				}
			}
		}

		return;
	}
	~Vol3DSimple()
	{
		if (data3d) delete3dpointer(data3d, sz.sz0, sz.sz1, sz.sz2);
		if (data1d) { delete[]data1d; data1d = 0; }
		sz.sz0 = sz.sz1 = sz.sz2 = len = 0;
	}

	bool valid() { return (data1d && data3d && len>0 && sz.valid()) ? true : false; }
	T *** getData3dHandle() { return data3d; }
	T * getData1dHandle() { return data1d; }
	V3DLONG getTotalElementNumber() { return len; }
	V3DLONG sz0() { return sz.sz0; }
	V3DLONG sz1() { return sz.sz1; }
	V3DLONG sz2() { return sz.sz2; }
	V3DLONG maxdimsz() { V3DLONG tmp = (sz.sz0>sz.sz1) ? sz.sz0 : sz.sz1; return (tmp>sz.sz2) ? tmp : sz.sz2; }
	V3DLONG mindimsz() { V3DLONG tmp = (sz.sz0<sz.sz1) ? sz.sz0 : sz.sz1; return (tmp<sz.sz2) ? tmp : sz.sz2; }

	bool padding(V3DLONG rx, V3DLONG ry, V3DLONG rz) //rx,ry, and rz are the border margin to be added
	{
		if (!valid()) return false;
		if (rx<0 || ry<0 || rz<0) return false;
		if (rx == 0 && ry == 0 && rz == 0) return true; //but do nothing

		Size3D sz_new(sz0() + 2 * rx, sz1() + 2 * ry, sz2() + 2 * rz);
		V3DLONG len_new = (V3DLONG)sz_new.sz0 * sz_new.sz1 * sz_new.sz2;
		T * data1d_new = new T[len_new];
		if (!data1d_new) return false;
		T *** data3d_new = 0;
		new3dpointer(data3d_new, sz_new.sz0, sz_new.sz1, sz_new.sz2, data1d_new);
		if (!data3d_new) { if (data1d_new) { delete[] data1d_new; data1d_new = 0; } return false; }
		V3DLONG i, j, k;
		for (i = 0; i<len_new; i++) data1d_new[i] = (T)0; //note that I feel a construction function ahs to be defined for a particular class if this function is called
		for (k = 0; k<sz.sz2; k++)
		{
			for (j = 0; j<sz.sz1; j++)
			{
				for (i = 0; i<sz.sz0; i++)
				{
					data3d_new[k + rz][j + ry][i + rx] = data3d[k][j][i];
				}
			}
		}

		//delete the old data
		T * data1d_tmp = data1d;
		T *** data3d_tmp = data3d;
		data1d = data1d_new;
		data3d = data3d_new;
		if (data3d_tmp) delete3dpointer(data3d_tmp, sz.sz0, sz.sz1, sz.sz2);
		if (data1d_tmp) { delete[]data1d_tmp; data1d_tmp = 0; }
		sz = sz_new;
		len = len_new;

		return true;
	}
	bool unpadding(V3DLONG rx, V3DLONG ry, V3DLONG rz) //rx,ry, and rz are the border margin to be removed
	{
		if (!valid()) return false;
		if (rx<0 || ry<0 || rz<0) return false;
		if (rx == 0 && ry == 0 && rz == 0) return true; //but do nothing

		Size3D sz_new(sz0() - 2 * rx, sz1() - 2 * ry, sz2() - 2 * rz);
		if (sz_new.sz0 <= 0 || sz_new.sz1 <= 0 || sz_new.sz2 <= 0) return false;

		V3DLONG len_new = (V3DLONG)sz_new.sz0 * sz_new.sz1 * sz_new.sz2;
		T * data1d_new = new T[len_new];
		if (!data1d_new) return false;
		T *** data3d_new = 0;
		new3dpointer(data3d_new, sz_new.sz0, sz_new.sz1, sz_new.sz2, data1d_new);
		if (!data3d_new) { if (data1d_new) { delete[] data1d_new; data1d_new = 0; } return false; }
		V3DLONG i, j, k;
		for (k = 0; k<sz_new.sz2; k++)
		{
			for (j = 0; j<sz_new.sz1; j++)
			{
				for (i = 0; i<sz_new.sz0; i++)
				{
					data3d_new[k][j][i] = data3d[k + rz][j + ry][i + rx];
				}
			}
		}

		//delete the old data
		T * data1d_tmp = data1d;
		T *** data3d_tmp = data3d;
		data1d = data1d_new;
		data3d = data3d_new;
		if (data3d_tmp) delete3dpointer(data3d_tmp, sz.sz0, sz.sz1, sz.sz2);
		if (data1d_tmp) { delete[]data1d_tmp; data1d_tmp = 0; }
		sz = sz_new;
		len = len_new;

		return true;
	}
};

template <class T> class Image2DSimple
{
private:
	Size2D sz;
	V3DLONG len;
	T * data1d;
	T ** data2d;

public:
	Image2DSimple() { sz.sz0 = sz.sz1 = len = 0; data1d = 0; data2d = 0; }
	Image2DSimple(V3DLONG s0, V3DLONG s1)
	{
		data1d = 0; data2d = 0;
		allocateMemory(s0, s1);
	}
	bool allocateMemory(V3DLONG s0, V3DLONG s1)
	{
		V3DLONG tmplen = s0*s1;
		if (tmplen>0 && s0>0 && s1>0)
		{
			data1d = new T[tmplen];
			if (data1d)
			{
				data2d = 0;
				new2dpointer(data2d, s0, s1, data1d);
				if (data2d)
				{
					sz.sz0 = s0;
					sz.sz1 = s1;
					len = tmplen;
					return true;
				}
				else
				{
					if (data1d) { delete[]data1d; data1d = 0; }
					sz.sz0 = sz.sz1 = len = 0;
					return false;
				}
			}
			else
			{
				sz.sz0 = sz.sz1 = len = 0;
				data1d = 0;
				data2d = 0;
				return false;
			}
		}
		else
		{
			sz.sz0 = sz.sz1 = len = 0;
			data1d = 0;
			data2d = 0;
			return false;
		}
		return true;
	}

	~Image2DSimple()
	{
		if (data2d) delete2dpointer(data2d, sz.sz0, sz.sz1);
		if (data1d) { delete[]data1d; data1d = 0; }
		sz.sz0 = sz.sz1 = len = 0;
	}

	bool valid() { return (data1d && data2d && len>0 && sz.valid()) ? true : false; }
	T ** getData2dHandle() { return data2d; }
	T * getData1dHandle() { return data1d; }
	V3DLONG getTotalElementNumber() { return len; }
	V3DLONG sz0() { return sz.sz0; }
	V3DLONG sz1() { return sz.sz1; }
	V3DLONG maxdimsz() { return (sz.sz0>sz.sz1) ? sz.sz0 : sz.sz1; }
	V3DLONG mindimsz() { return (sz.sz0<sz.sz1) ? sz.sz0 : sz.sz1; }
	bool bounadry_masking(V3DLONG margin, T tval)
	{
		if (!valid() || margin<0 || margin >= sz.sz0 || margin >= sz.sz1)
			return false;
		V3DLONG i, j;

		for (j = 0; j<margin; j++)
		{
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] = tval;
		}
		for (j = sz.sz1 - margin; j<sz.sz1; j++)
		{
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] = tval;
		}

		for (j = 0; j<sz.sz1; j++)
		{
			for (i = 0; i<margin; i++)
				data2d[j][i] = tval;
		}
		for (j = 0; j<sz.sz1; j++)
		{
			for (i = sz.sz0 - margin; i<sz.sz0; i++)
				data2d[j][i] = tval;
		}

		return true;
	}
	template <class Tnew> bool copy(Image2DSimple <Tnew> *img0, V3DLONG d0m, V3DLONG d0M, V3DLONG d1m, V3DLONG d1M)
	{
		if (!img0 || !img0->valid()) return false;

		V3DLONG s0m = (d0m<0) ? 0 : d0m, s0M = (d0M<0) ? 0 : s0M, s1m = (d1m<0) ? 0 : d1m, s1M = (d1M<0) ? 0 : d1M;
		s0m = (s0m >= img0->sz0()) ? img0->sz0() - 1 : s0m;
		s0M = (s0M >= img0->sz0()) ? img0->sz0() - 1 : s0M;
		s1m = (s1m >= img0->sz1()) ? img0->sz1() - 1 : s1m;
		s1M = (s1M >= img0->sz1()) ? img0->sz1() - 1 : s1M;
		V3DLONG tmp;
		if (s0m>s0M) { tmp = s0m; s0m = s0M; s0M = tmp; }
		if (s1m>s1M) { tmp = s1m; s1m = s1M; s1M = tmp; }

		V3DLONG s0 = s0M - s0m + 1, s1 = s1M - s1m + 1;
		if (s0 != sz.sz0 || s1 != sz.sz1)
		{
			if (data2d) delete2dpointer(data2d, sz.sz0, sz.sz1);
			if (data1d) { delete[]data1d; data1d = 0; }
			if (allocateMemory(s0, s1) == false)
				return false;
		}

		Tnew ** img0_p2d = img0->getData2dHandle();
		V3DLONG i, j;
		for (j = 0; j<s1; j++)
		{
			for (i = 0; i<s0; i++)
			{
				data2d[j][i] = (T)(img0_p2d[j + s1m][i + s0m]);
			}
		}
	}
	template <class Tnew> bool copy(Image2DSimple <Tnew> *img0)
	{
		if (!img0 || !img0->valid()) return false;

		V3DLONG s0 = img0->sz0(), s1 = img0->sz1();
		if (s0 != sz.sz0 || s1 != sz.sz1)
		{
			if (data2d) delete2dpointer(data2d, sz.sz0, sz.sz1);
			if (data1d) { delete[]data1d; data1d = 0; }
			if (allocateMemory(s0, s1) == false)
				return false;
		}

		Tnew ** img0_p2d = img0->getData2dHandle();
		V3DLONG i, j;
		for (j = 0; j<s1; j++)
		{
			for (i = 0; i<s0; i++)
			{
				data2d[j][i] = (T)(img0_p2d[j][i]);
			}
		}
	}
	template <class Tnew> bool copy(Tnew **img0, V3DLONG img0sz0, V3DLONG img0sz1, V3DLONG d0m, V3DLONG d0M, V3DLONG d1m, V3DLONG d1M)
	{
		if (!img0) return false;

		V3DLONG s0m = (d0m<0) ? 0 : d0m, s0M = (d0M<0) ? 0 : d0M, s1m = (d1m<0) ? 0 : d1m, s1M = (d1M<0) ? 0 : d1M;
		s0m = (s0m >= img0sz0) ? img0sz0 - 1 : s0m;
		s0M = (s0M >= img0sz0) ? img0sz0 - 1 : s0M;
		s1m = (s1m >= img0sz1) ? img0sz1 - 1 : s1m;
		s1M = (s1M >= img0sz1) ? img0sz1 - 1 : s1M;
		V3DLONG tmp;
		if (s0m>s0M) { tmp = s0m; s0m = s0M; s0M = tmp; }
		if (s1m>s1M) { tmp = s1m; s1m = s1M; s1M = tmp; }

		V3DLONG s0 = s0M - s0m + 1, s1 = s1M - s1m + 1;
		if (s0 != sz.sz0 || s1 != sz.sz1)
		{
			if (data2d) delete2dpointer(data2d, sz.sz0, sz.sz1);
			if (data1d) { delete[]data1d; data1d = 0; }
			if (allocateMemory(s0, s1) == false)
				return false;
		}

		V3DLONG i, j;
		for (j = 0; j<s1; j++)
		{
			for (i = 0; i<s0; i++)
			{
				data2d[j][i] = (T)(img0[j + s1m][i + s0m]);
			}
		}
	}
	template <class Tnew> void plus(Tnew a)
	{
		if (!valid()) return;
		V3DLONG i, j;
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] += (T)a;
	}
	template <class Tnew> bool plus(Image2DSimple <Tnew> * a)
	{
		if (!valid() || !a || !a->valid()) return false;
		if (sz.sz0 != a->sz0() || sz.sz1 != a->sz1()) return false;

		Tnew ** a2d = a->getData2dHandle();
		V3DLONG i, j;
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] += (T)(a2d[j][i]);

		return true;
	}
	template <class Tnew> bool subtract(Image2DSimple <Tnew> * a)
	{
		if (!valid() || !a || !a->valid()) return false;
		if (sz.sz0 != a->sz0() || sz.sz1 != a->sz1()) return false;

		Tnew ** a2d = a->getData2dHandle();
		V3DLONG i, j;
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] -= (T)(a2d[j][i]);

		return true;
	}

	template <class Tnew> void time(Tnew a)
	{
		if (!valid()) return;
		V3DLONG i, j;
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				data2d[j][i] *= (T)a;
	}

	T sum()
	{
		if (!valid()) return 0;
		V3DLONG i, j;
		double v = 0;
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				v += double(data2d[j][i]);
		return (T)v;
	}
	T min()
	{
		if (!valid()) return 0;
		V3DLONG i, j;
		T v = data1d[0][0];
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				v = (v>data2d[j][i]) ? data2d[j][i] : v;
		return v;
	}
	T max()
	{
		if (!valid()) return 0;
		V3DLONG i, j;
		T v = data1d[0][0];
		for (j = 0; j<sz.sz1; j++)
			for (i = 0; i<sz.sz0; i++)
				v = (v<data2d[j][i]) ? data2d[j][i] : v;
		return v;
	}
	template <class Tnew> void setValue(Tnew **img0, V3DLONG img0sz0, V3DLONG img0sz1, T value, int flag) //img0 is the mask
	{
		if (img0sz0 != sz.sz0 || img0sz1 != sz.sz1) return; //do nothing if the sizes are different
		V3DLONG i, j;
		if (flag) //if flag is 0, then where img0 is 0 will be set as 0; if flag=1, the  where img0 is non-zero will be set as 0.
		{
			for (j = 0; j<sz.sz1; j++)
			{
				for (i = 0; i<sz.sz0; i++)
				{
					if (img0[j][i]) data2d[j][i] = value;
				}
			}
		}
		else
		{
			for (j = 0; j<sz.sz1; j++)
			{
				for (i = 0; i<sz.sz0; i++)
				{
					if (!(img0[j][i])) data2d[j][i] = value;
				}
			}
		}
	}
	template <class Tnew> void setValue(Tnew a)
	{
		if (!valid()) return;
		for (V3DLONG i = 0; i<len; i++) data1d[i] = (T)a;
	}
	template <class Tnew> bool plus_subimage(Tnew ** sa, V3DLONG d0, V3DLONG d1, V3DLONG s0m, V3DLONG s0M, V3DLONG s1m, V3DLONG s1M) //this image plus a sub-region of a new subject
	{
		if (!sa || d0 <= 0 || d1 <= 0 || s0m<0 || s0M<0 || s0M<s0m || s1m<0 || s1M<0 || s1M<s1m)
			return false;

		if ((d0<s0M - s0m + 1) || (d1<s1M - s1m + 1) || sz.sz0 != s0M - s0m + 1 || sz.sz1 != s1M - s1m + 1)
		{
			fprintf(stderr, "Unmatched sizes in vol2d_plus_subimage() \n.");
			return false;
		}

		V3DLONG i, j, i2, j2;
		for (j = 0; j<sz.sz1; j++)
		{
			j2 = j + s1m;
			if (j2<0 || j2 >= d1) continue; //070509
			for (i = 0; i<sz.sz0; i++)
			{
				i2 = i + s0m;
				if (i2<0 || i2 >= d0) continue; //070509
				data2d[j][i] += sa[j2][i2];
			}
		}

		return true;
	}
	template <class Tnew> bool subimage_plus(V3DLONG s0m, V3DLONG s0M, V3DLONG s1m, V3DLONG s1M, Tnew ** sa, V3DLONG d0, V3DLONG d1) //a subset region of this image plus a new subject
	{
		if (!sa || d0 <= 0 || d1 <= 0 || s0m<0 || s0M<0 || s0M<s0m || s1m<0 || s1M<0 || s1M<s1m)
			return false;

		if ((d0 != s0M - s0m + 1) || (d1 != s1M - s1m + 1) || (sz.sz0<s0M - s0m + 1) || (sz.sz1<s1M - s1m + 1))
		{
			fprintf(stderr, "Unmatched sizes in vol2d_plus_subimage() \n.");
			return false;
		}

		V3DLONG i, j, j2, i2;
		for (j = 0; j<d1; j++)
		{
			j2 = j + s1m;
			if (j2<0 || j2 >= sz.sz1) continue; //070509

			for (i = 0; i<d0; i++)
			{
				i2 = i + s0m;
				if (i2<0 || i2 >= sz.sz0) continue; //070509
				data2d[j2][i2] += sa[j][i];
			}
		}

		return true;
	}
	template <class Tnew> bool subimage_plus_subimage(V3DLONG s0m, V3DLONG s0M, V3DLONG s1m, V3DLONG s1M, Tnew ** sa, V3DLONG d0, V3DLONG d1, V3DLONG d0m, V3DLONG d0M, V3DLONG d1m, V3DLONG d1M)
		//a subset region of this image plus a subimage of a new subject
	{
		if (!sa ||
			d0 <= 0 || d1 <= 0 || d0m<0 || d0M<0 || d0M<d0m || d1m<0 || d1M<0 || d1M<d1m ||
			s0m<0 || s0M<0 || s0M<s0m || s1m<0 || s1M<0 || s1M<s1m)
			return false;

		if ((d0M - d0m != s0M - s0m) || (d1M - d1m != s1M - s1m) || (sz.sz0<s0M - s0m + 1) || (sz.sz1<s1M - s1m + 1) ||
			(d0<d0M - d0m + 1) || (d1<d1M - d1m + 1))
		{
			fprintf(stderr, "Unmatched sizes in vol2d_plus_subimage() \n.");
			return false;
		}

		V3DLONG i, j;
		for (j = 0; j<d1M - d1m + 1; j++)
		{
			for (i = 0; i<d0M - d0m + 1; i++)
			{
				data2d[j + s1m][i + s0m] += sa[j + d1m][i + d0m];
			}
		}

		return true;
	}
};

#endif