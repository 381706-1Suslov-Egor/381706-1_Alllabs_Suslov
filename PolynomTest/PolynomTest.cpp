#include "gtest.h"
#include "Polynom.h"
int mas1[] = { 1, 2, 3 };
int mas2[] = { 1, 0, 2 };
int mas3[] = { 1, -2, 2 };
int mas4[] = { 1, 2, 3, 4 };
int mas5[] = { 4, 5, 6 };
TMonom A(3, mas1, 1);
TMonom B(3, mas2, 2);
TMonom C(4, mas4, 1);
TMonom D(3, mas5, 3);
TMonom E(3, mas1, 0);

TEST(TMonom, can_create_monom_with_zero_size)
{
	ASSERT_NO_THROW(TMonom J(0, mas1, 1));
}

TEST(TMonom, can_create_monom)
{
	ASSERT_NO_THROW(TMonom J(3, mas1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_kol_peremennih)
{
	ASSERT_ANY_THROW(TMonom J(-1, mas1, 1));
}

TEST(TMonom, throws_when_create_monom_with_negative_power)
{
	ASSERT_ANY_THROW(TMonom J(3, mas3, 1));
}

TEST(TMonom, can_create_copy_monom)
{
	TMonom Y(1, mas1, 1);
	ASSERT_NO_THROW(TMonom U(Y));
}

TEST(TMonom, can_set_and_get_next)
{
	TMonom X(3, mas1, 1);
	TMonom Z(3, mas2, 1);
	ASSERT_NO_THROW(X.SetNext(&Z));
	ASSERT_EQ(X.GetNext(), &Z);
}

TEST(TMonom, can_set_and_get_c)
{
	TMonom X(3, mas1, 12);
	ASSERT_NO_THROW(X.SetC(3.14));
	ASSERT_EQ(3.14, X.GetC());
}

TEST(TMonom, can_set_and_get_power)
{
	TMonom X(3, mas1, 1);
	ASSERT_NO_THROW(X.SetPower(mas2));
	ASSERT_EQ(mas2[0], X.GetPower()[0]);
	ASSERT_EQ(mas2[1], X.GetPower()[1]);
	ASSERT_EQ(mas2[2], X.GetPower()[2]);
}

TEST(TMonom, can_set_and_get_n_max)
{
	TMonom X(3, mas1, 1);
	ASSERT_NO_THROW(X.SetN(5));
	ASSERT_EQ(5, X.GetN());
}

TEST(TMonom, can_set_and_get_n_min)
{
	TMonom X(3, mas1, 1);
	ASSERT_NO_THROW(X.SetN(1));
	ASSERT_EQ(1, X.GetN());
}


TEST(TMonom, throws_when_assign_monoms_with_different_n)
{
	TMonom X(3, mas1, 1);
	TMonom Z(4, mas2, 4);
	ASSERT_ANY_THROW(X = Z);
}

TEST(TMonom, can_equal_monoms)
{
	TMonom X(3, mas1, 4.5);
	TMonom Z(3, mas1, 1.0);
	ASSERT_NO_THROW(X + Z);
	TMonom Y(3, mas1, 1);
	Y = X + Z;
	ASSERT_EQ(5.5, Y.GetC());
}

TEST(TMonom, trows_when_add_different_monoms)
{
	TMonom X(3, mas1, 3.6);
	TMonom Z(3, mas2, 1.0);
	TMonom Y(4, mas4, 1);
	ASSERT_ANY_THROW(X + Z);
	ASSERT_ANY_THROW(X + Y);
}

TEST(TMonom, can_substract_equal_monoms)
{
	TMonom X(3, mas1, 3.6);
	TMonom Z(3, mas1, 1.0);
	ASSERT_NO_THROW(X - Z);
	TMonom Y(3, mas1, 1);
	Y = X - Z;
	ASSERT_EQ(2.6, Y.GetC());
}

TEST(TMonom, trows_when_substract_different_monoms)
{
	TMonom X(3, mas1, 3.6);
	TMonom Z(3, mas2, 1.0);
	TMonom Y(4, mas4, 1);
	ASSERT_ANY_THROW(X - Z);
	ASSERT_ANY_THROW(X - Y);
}



TEST(TMonom, trows_when_multiply_different_monoms)
{
	TMonom X(3, mas1, 2);
	TMonom Z(4, mas4, 2);
	ASSERT_ANY_THROW(X * Z);
}

TEST(TMonom, can_equivalence_monoms)
{
	TMonom X(3, mas1, 3.1);
	TMonom Z(3, mas1, 3.1);
	TMonom Y(3, mas2, 3.1);
	ASSERT_TRUE(X == Z);
	ASSERT_FALSE(X == Y);
}

TEST(TMonom, trows_when_equivalence_monoms_with_different_n)
{
	TMonom X(3, mas1, 1);
	TMonom Z(4, mas4, 1);
	ASSERT_ANY_THROW(X == Z);
}

TEST(TMonom, can_compare_equal_monoms)
{
	TMonom X(3, mas1, 1);
	TMonom Z(3, mas2, 2);
	ASSERT_TRUE(X > Z);
	ASSERT_FALSE(X < Z);
	TMonom Y(3, mas5, 4);
	ASSERT_TRUE(X < Y);
	ASSERT_FALSE(Y < X);
}

TEST(TMonom, trows_compare_monoms_with_different_n)
{
	TMonom X(3, mas1, 1);
	TMonom Z(4, mas4, 2);
	ASSERT_ANY_THROW(X > Z);
	ASSERT_ANY_THROW(X < Z);
}

TEST(TMonom, trows_compare_when_monoms_eq)
{
	TMonom X(3, mas1, 1);
	TMonom Z(3, mas1, 2);
	ASSERT_ANY_THROW(X > Z);
	ASSERT_ANY_THROW(Z < X);
}
TEST(TPolynom, can_create_polynom)
{
  ASSERT_NO_THROW(TPolynom P(3));
}

TEST(TPolynom, throws_when_create_polynom_with_negative_size)
{
  ASSERT_ANY_THROW(TPolynom P(-3));
}

TEST(TPolynom, can_create_copy_polynom)
{
  TPolynom P(3);
  P += A;
  P += B;
  ASSERT_NO_THROW(TPolynom Q(P));
  TPolynom Q(P);
  ASSERT_TRUE(Q == P);
}

TEST(TPolynom, can_get_size_polynom)
{
  TPolynom P(3);
  P += A;
  P += B;
  ASSERT_EQ(P.GetSize(), 2);
}

TEST(TPolynom, trows_when_add_different_polynoms)
{
  TPolynom P(4);
  P += C;
  TPolynom Q(3);
  Q += A;
  ASSERT_ANY_THROW(P + Q);
}

TEST(TPolynom, can_add_equal_polynoms)
{
  TPolynom P(3);
  P += A;
  P += B;
  TPolynom Q(3);
  Q += A;
  Q += D;
  ASSERT_NO_THROW(P + Q);
  TPolynom U(3);
  U = P + Q;
  TMonom* a = U.GetStart();
  ASSERT_EQ(3, U.GetSize());
  ASSERT_TRUE(*a == D);
  a = a->GetNext();
  ASSERT_TRUE(*a == A);
  a = a->GetNext();
  ASSERT_TRUE(*a == B);
  a = a->GetNext();
  ASSERT_TRUE(a == 0);
}

TEST(TPolynom, trows_when_minus_different_polynoms)
{
  TPolynom P(4);
  P += C;
  TPolynom Q(3);
  Q += A;
  ASSERT_ANY_THROW(P - Q);
}

TEST(TPolynom, can_minus__polynoms)
{
  TPolynom P(3);
  P += A;
  P += B;
  TPolynom Q(3);
  Q += A;
  Q += D;
  ASSERT_NO_THROW(P - Q);
  TPolynom U(3);
  U = P - Q;
  TMonom* a = U.GetStart();
  ASSERT_EQ(2, U.GetSize());
  ASSERT_TRUE(*a == D);
  ASSERT_TRUE(a->GetC() == -3);
  a = a->GetNext();
  ASSERT_TRUE(*a == B);
  ASSERT_TRUE(a->GetC() == 2);
  a = a->GetNext();
  ASSERT_TRUE(a == 0);
}

TEST(TPolynom, appoint_operator_polynoms_work)
{
  TPolynom P(3);
  P += A;
  P += E;
  TPolynom Q(3);
  Q += B;
  Q += D;
  ASSERT_NO_THROW(P = Q);
  TMonom* a = P.GetStart();
  ASSERT_TRUE(*a == D);
  ASSERT_EQ(3, a->GetC());
  a = a->GetNext();
  ASSERT_TRUE(*a == B);
  ASSERT_EQ(2, a->GetC());
  a = a->GetNext();
  ASSERT_TRUE(a == 0);
}

TEST(TPolynom, throws_when_appoint_monoms_with_different_n)
{
  TPolynom P(4);
  TPolynom Q(3);
  ASSERT_ANY_THROW(P = Q);
}

TEST(TPolynom, can_equivalence_polynoms_now)
{
  TPolynom P(3);
  P += A;
  P += E;
  TPolynom Q(3);
  Q += B;
  Q += D;
  ASSERT_FALSE(P == Q);
  Q = P;
  ASSERT_TRUE(P == Q);
  TMonom M(3, mas1, 2);
  TPolynom J(3);
  J += A;
  TPolynom K(3);
  K += M;
  ASSERT_FALSE(J == K);
}

TEST(TPolynom, trows_when_compare_polynoms_with_different_n)
{
  TPolynom M(3);
  TPolynom N(4);
  ASSERT_ANY_THROW(M == N);
}



TEST(TPolynom, trows_when_multiply_different_polynoms)
{
  TPolynom P(3);
  TPolynom Q(4);
  ASSERT_ANY_THROW(P * Q);
}

TEST(TPolynom, can_plus_equals_polynoms)
{
  TPolynom Q(3);
  Q += B;
  Q += D;
  TMonom* a = Q.GetStart();
  ASSERT_TRUE(*a == D);
  ASSERT_EQ(a->GetC(), 3);
  a = a->GetNext();
  ASSERT_TRUE(*a == B);
  ASSERT_EQ(a->GetC(), 2);
  a = a->GetNext();
  ASSERT_TRUE(a == NULL);
}

TEST(TPolynom, trows_when_plus_eq_different_polynoms)
{
  TPolynom P(3);
  ASSERT_ANY_THROW(P += C);
}

TEST(TPolynom, can_minus_eq_polynoms)
{
  TPolynom Q(3);
  Q -= B;
  Q += A;
  Q -= D;
  TMonom* a = Q.GetStart();
  ASSERT_TRUE(*a == D);
  ASSERT_EQ(a->GetC(), -3);
  a = a->GetNext();
  ASSERT_TRUE(*a == A);
  ASSERT_EQ(a->GetC(), 1);
  a = a->GetNext();
  ASSERT_TRUE(*a == B);
  ASSERT_EQ(a->GetC(), -2);
  a = a->GetNext();
  ASSERT_TRUE(a == NULL);
}
TEST(TPolynom, can_add_monoms_to_polynoms)
{
	int m1[3] = { 1, 2, 3 };
	int m2[4] = { 2, 1, 4 };
	TMonom tmp1(3, m1, 1);
	TMonom tmp2(3, m2, 2);
	TPolynom A(3);
	A += tmp1;
	A += tmp2;
	TMonom* a = A.GetStart();
	ASSERT_TRUE(*a == tmp2);
	a = a->GetNext();
	ASSERT_TRUE(*a == tmp1);
	a = a->GetNext();
	ASSERT_TRUE(a == NULL);
}



