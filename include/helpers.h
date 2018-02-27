template<typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
	T alpha;
	T beta;
	Vector<T> x_k = x;
	Vector<T> r_k = b - A.matvec(x);
	Vector<T> p_k = r_k;
	for (int k = 0; k < maxiter; k++) {
		alpha = dot(r_k, r_k) / dot(p_k, A.matvec(p_k));
		x = x_k + alpha*p_k;
		Vector<T> r_new = r_k - alpha*A.matvec(p_k);
		// Check threshold
		if (dot(r_new, r_new) < tol*tol) {
			return k;
		}
		// re-init
		beta = (dot(r_new, r_new)) / dot(r_k, r_k);
		p_k = r_new + beta*p_k;
		x_k = x;
		r_k = r_new;
	}
	int k = -1;
	return k;
}