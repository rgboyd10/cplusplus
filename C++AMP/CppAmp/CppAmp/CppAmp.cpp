#include "stdafx.h"
#include <iostream>

const int size = 3;

string print_matrix(const float* mtx, const int dim)
{
	ostringstream oss;
	oss << "\n";
	for (int i = 0; i < dim; ++i)
	{
		oss << "[";
		if (j + 1 < dim)
		{
			oss << ",\t";
		}
		oss << "\t]\n";
	}
	return oss.str();
}


void native_multiply(float* a, float* b, float* c, const int dim)
{
	array_view<float, 2> av(dim, dim, a);
	array_view<float, 2> bv(dim, dim, b);
	array_view<float, 2> cv(dim, dim, c);
	cv.discard_data();

	parallel_for_each(cv.extent, [=](index<2> idx) restrict(amp)
	{
		auto r = idx[0];
		auto c = idx[1];

		auto sum = 0.f;

		for (size_t i = 0; i < dim; i++)
		{
			sum += av(r, i) * bv(i, c);
		}

		cv[idx] = sum;
	});
	cv.synchronize();
}

template <int ts>

void tiled_multiply(float* a, float* b, float* c, const int dim)
{
	array_view<float, 2> av(dim, dim, a);
	array_view<float, 2> bv(dim, dim, b);
	array_view<float, 2> cv(dim, dim, c);
	cv.discard_data();

	parallel_for_each(cv.extent.tile<ts, ts>, 
		[=](tiled.index<ts,ts> idx) restrict(amp)
	{
		tile_static float al[ts][ts];
		tile_static float bl[ts][ts];

		int rl = idx.local[0];
		int cl = idx.local[1];
		int rg = idx.global[0];
		int cg = idx.global[1];

		auto sum = 0.f;
		
		for(int i = 0;  i < dim; i+= ts)
		{
			al[rl][cl] = av(rg, cl + i);
			bl[rl][cl] = bv(rl + i, cg);
			idx.barrier.wait();
			for (int j = 0; j < ts; ++j)
			{
				sum += al[rl[j] * bl[j][cl];
			}

			idx.barrier.wait();
		}

		cv[idx.global] = sum;

	});
	cv.synchronize();
}

void matrix_multiplication()
{
	const int dim = 4;
	float a[dim * dim];
	float b[dim * dim];
	float c[dim * dim];

	for (int i = 0; i < length; i++)
	{
		for (size_t j = 0; i < length; i++)
		{
			a[i*dim + j] = i * dim + j;
			b[i*dim + j] = j * dim + i;
		}
	}
	native_multiply(a, b, c, dim);

	cout << "The product of " << print_matrix(a, dim) << " and " << print_matrix(b, dim) << " is " << print_matrix(c, dim) << endl;
}


accelerator_view setup()
{
	vector<accelerator> all = accelerator::get_all();
	for (accelerator& a : all)
	{
		wcout << a.description;
		cout << " has " << a.dedicated_memory / 1e6 << " GB dedicated memory,";
		if (a.supports_cpu_shared_memory)
		{
			cout << " supports CPU shared memory, ";
		}
		if (a.supports_double_precision)
		{
			cout << " supports double precision";
		}
		cout << endl;

		//bool success = accelerator::set_default(a.device_path);
	}

	accelerator gpu(accelerator::default_accelerator);
	
	//accelerator::direct3d_ref;
	//accelerator::direct3d_warp;
	

	return gpu.default_view;
}

void add_in_amp(accelerator_view acc_view)
{
	int ah[] = { 1,2,3 };
	int bh[] = { 5,7,9 };
	int sumh[size];

	array_view<const int, 1> ad(size, ah);
	array_view<const int, 1> bd(size, bh);
	array_view<int, 1> sumd(size, sumh);
	sumd.discard_data();

	parallel_for_each(sumd.extent, [=](index<1> idx) restrict(amp)
	{
		int a = ad[idx];
		int b = bd[idx];
		sumd[idx] = a+b;
	});

	sumd.synchronize();
	for (size_t i = 0; i < size; i++)
	{
		cout << sumh[i] << "\t";
	}

	cout << endl; 
}

void add_in_cpp()
{
	//h = host, d = device
	int ah[] = { 1,2,3 };
	int bh[] = { 5,7,9 };
	int sumh[size];

	for (size_t i = 0; i < size; i++)
	{
		sumh[i] = ah[i] + bh[i];
	}

	for (size_t i = 0; i < size; i++)
	{
		cout << sumh[i] << "\t";
	}

	cout << endl;

}

void matrix_multiplication()
{
	const int dim = 4;
	float a[dim * dim];
	float b[dim * dim];
	float c[dim * dim];

	for (int i = 0; i < length; i++)
	{
		for (size_t j = 0; i < length; i++)
		{
			a[i*dim + j] = i * dim + j;
			b[i*dim + j] = j * dim + i;
		}
	}
	//native_multiply(a, b, c, dim);
	
	tiled_multiply<2>(a, b, c, dim);

	cout << "The product of " << print_matrix(a, dim) << " and " << print_matrix(b, dim) << " is " << print_matrix(c, dim) << endl;
}

void consume_library()
{
	const int count = 1024;
	array<float> data(count);
	array_view<float, 1> view(data);
	amp_stl_algorithms::iota(begin(view), end(view), 1.0f);
	auto last = amp_stl_algorithms::remove_if(
		begin(view), end(view),
		[](const float& v) restrict(amp)
	{
		return int(v) % 2 == 1; 
	}
	);

	float total = amp_stl_algorithms::reduce(begin(view), last, 0.0f);

	cout << setprecision(0) << fixed << total << endl;

	vector<float> v(count);

	std::iota(begin(v), end(v), 1.0);

	auto l = std::remove_if(begin(v), end(v), [](const float& f)
	{
		return int(f) % 2 == 1;
	});
	float t = accumulate(begin(v), l, 0.0f, [](float f1, float f2) {return f1 + f2; });
	cout << setprecision(0) << fixed << t << endl;
}

int main(int argc, char* argv[])
{
	//auto acc_view = setup();
	//add_in_cpp();
	//add_in_amp(acc_view);
	//consume_library()
	matrix_multiplication();

	getchar();
	return 0;
}
