#include "../PolygonalChain_Seb_Library/Simple2DGeometry.h"
#include "../PolygonalChain_Seb_Library/PolygonalChain_Seb.h"

#define __NUMBER_OF_RANDOM_POINTS__ 10240

int main()
{
	cout << "************* Examples with stack variables *************" << endl << endl;

	Point2D O;
	cout << "Point2D O - Default Construction" << endl << O << endl << endl;


	Point2D A("A");
	cout << "Point2D A - Construction with point name only" << endl << A << endl << endl;



	Point2D B(5, -2.358);
	cout << B.toString();
	cout << B;
	cout << "Point2D B - Construction with X & Y but no name" << endl << B << endl << endl;
	B = "B";
	cout << "Point2D B - Renaming to ""B"" with a specific operator= overload" << endl << B << endl << endl;


	Point2D BPrime(B);
	BPrime = "B'";
	cout << "Point2D BPrime - Instanciated by copy constructor from point B and rename" << endl << BPrime << endl << endl;

	cout << "B == B': ";

	if (B == BPrime)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	Point2D BSecond;
	BSecond = BPrime;
	BSecond = "B''";
	cout << "Point2D BSecond - Constructed by default, equalised to point BPrime with operator= and rename" << endl << BSecond << endl << endl;

	cout << "B == B'': ";
	if (B == BSecond)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	Point2D C(1, 2, "C");
	cout << "Point2D C - Full construction" << endl << C << endl << endl;


	try
	{
		cout << "X value of point " << C.getName() << " is " << C[0] << endl;
		cout << "Y value of point " << C.getName() << " is " << C[1] << endl;
		cout << "Y value of point " << C.getName() << " is " << C[25] << endl;
	}
	catch (invalid_argument ex)
	{

	}
	catch (exception ex)
	{
		cout << ex.what() << endl << endl;
	}

	//This is now possible (try it), but it's a terrible idea!
	//WHY?
	//C[0] = 68.6;

	Point2D D(2, 4, "D");
	cout << "Point2D D - Full construction" << endl << D << endl << endl;

	StraightLine SL2(C, D);
	SL2.~StraightLine();

	StraightLine SLO;
	StraightLine SL1(O, A);



	C[0] = 1;
	cout << SLO << endl;
	cout << SL1 << endl;
	cout << SL2 << endl << endl;

	cout << "SLO == SL1: ";

	if (SLO == SL1)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "SL1 == SL2: ";
	if (SL1 == SL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	Point2D E(1, 2, "E");
	Point2D F(2, 4, "F");
	Point2D FPrime(2, 4, "F'");
	Point2D G(3, 6, "G");

	LineSegment LS1(E, F);
	cout << LS1 << endl << endl;

	LineSegment LS2(E, FPrime);
	cout << LS2 << endl << endl;

	LineSegment LS3(F);
	cout << LS3 << endl << endl;

	LineSegment LS4(E, G);
	cout << LS4 << endl << endl;

	LineSegment LS5(SLO);
	cout << LS5 << endl << endl;

	LineSegment LS6(SL2);
	cout << LS6 << endl << endl;

	LineSegment LS7(D, C);
	cout << LS7 << endl << endl;

	LineSegment LS8(C, D);
	cout << LS7 << endl << endl;


	cout << "LS6(C,D) == LS7(D,C): ";
	if (LS6 == LS7)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS7(D,C) == LS6(C,D): ";
	if (LS7 == LS6)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS6(D,C) == SL2(C,D): ";
	if (LS6 == SL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS7(D,C) == SL2(C,D): ";
	if (LS7 == SL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS8(C,D) == LS4(E,G) - Same StraigtLine, is LineSegment the same?: ";
	if (LS8 == LS4)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	StraightLine SL3(E, G);
	cout << "SL2(C,D) == SL3(E,G) - Comparison with two StraigthLine object on different points: ";
	if (SL2 == SL3)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;



	cout << "Polymorphism test with a collection of StraightLine, mixing StraightLine & LineSegment objects" << endl;
	cout << "Using the std::vector class of the C++ STL" << endl << endl;

	vector<StraightLine> mySLCollection;
	mySLCollection.push_back(LS6);
	mySLCollection.push_back(LS7);
	mySLCollection.push_back(SL2);
	mySLCollection.push_back(SL3);

	cout << "LS6(C,D) {mySLCollection[0]} == LS7(D,C) {mySLCollection[1]} : ";
	if (mySLCollection[0] == mySLCollection[1])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS6(C,D) {mySLCollection[0]} == SL2(C,D) {mySLCollection[2]} : ";
	if (mySLCollection[0] == mySLCollection[2])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	cout << "LS6(C,D) {mySLCollection[0]} == SL3(E,G) {mySLCollection[3]} - Same StraightLine, different LineSegment" << endl;
	cout << "This should leverage FALSE, let's see: ";
	if (mySLCollection[0] == mySLCollection[3])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "SL2(C,D) {mySLStarCollection[2]} == SL3(E,G) {mySLStarCollection[3]} - Same StraightLine, different points: ";
	if (mySLCollection[2] == mySLCollection[3])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "Oh no! Polymorphism doesn't work! But you should expect this behaviour, shoudln't you?!" << endl << endl;


	//IMPORTANT - ITERATING THROUGH THE VECTOR WITH AN ITERATOR OBJECT (STL)
	// this class has many capacities and many operators overload to use them
	// as the operator ++ used in the for loop below!
	vector<StraightLine>::iterator objSLIterator;

	for (objSLIterator = mySLCollection.begin(); objSLIterator != mySLCollection.end(); objSLIterator++)
	{
		//An STL iterator is an pointer on the underlying collection element
		//Here, the collection is a vector<StraightLine*>
		//Taking the star (*) of an iterator instance, such as here *objIterator, provides a StraightLine*
		//or whichever type the collection is made of;
		// Having the operator << overload here is immensely useful
		// and of course, polymorphism DOESN't WORK here (objects all printed as StraightLine), for the same reason as above :)
		cout << *objSLIterator << endl;
	}
	cout << endl;


	cout << "************* End of ex. with stack variables *************" << endl << endl << endl;






	cout << "************* Examples with dynamically allocated objects in the heap *************" << endl << endl;


	Point2D* pO = new Point2D;
	cout << "Point2D O - Default Construction" << endl << pO << endl << endl;


	Point2D* pA = new Point2D("A");
	cout << "Point2D A - Construction with point name only" << endl << pA << endl << endl;

	Point2D* pB = new Point2D(5, -2.358);
	cout << "Point2D B - Construction with X & Y but no name" << endl << pB << endl << endl;
	*pB = "B";
	cout << "Point2D B - Renaming to ""B"" with setName()" << endl << pB << endl << endl;


	Point2D* pBPrime = new Point2D(pB);
	*pBPrime = "B'";
	cout << "Point2D BPrime - Instanciated by copy constructor from point B and rename" << endl << *pBPrime << endl << endl;

	cout << "B == B': ";

	if (*pB == pBPrime)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	Point2D* pBSecond = new Point2D;
	*pBSecond = pBPrime;
	*pBSecond = "B''";
	cout << "Point2D BSecond - Constructed by default, equalised to point BPrime with operator= and rename" << endl << *pBSecond << endl << endl;

	cout << "B == B'': ";
	if (*pB == pBSecond)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	Point2D* pC = new Point2D(1, 2, "C");
	cout << "Point2D C - Full construction" << endl << pC << endl << endl;


	try
	{
		cout << "X value of point " << pC->getName() << " is " << (*pC)[0] << endl;
		cout << "Y value of point " << pC->getName() << " is " << (*pC)[1] << endl;
		cout << "Y value of point " << pC->getName() << " is " << (*pC)[25] << endl;
	}
	catch (exception ex)
	{
		cout << ex.what() << endl << endl;
	}

	//This is now possible (try it), but it's a terrible idea!
	//(*pC)[0] = 68.6;

	Point2D* pD = new Point2D(2, 4, "D");
	cout << "Point2D D - Full construction" << endl << pD << endl << endl;



	StraightLine* pSLO = new StraightLine();
	StraightLine* pSL1 = new StraightLine(pO, pA);
	StraightLine* pSL2 = new StraightLine(pC, pD);

	cout << pSLO << endl;
	cout << pSL1 << endl;
	cout << pSL2 << endl << endl;

	cout << "SLO == SL1: ";

	if (*pSLO == pSL1)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "SL1 == SL2: ";
	if (*pSL1 == pSL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	Point2D* pE = new Point2D(1, 2, "E");
	Point2D* pF = new Point2D(2, 4, "F");
	Point2D* pFPrime = new Point2D(2, 4, "F'");
	Point2D* pG = new Point2D(3, 6, "G");

	LineSegment* pLS1 = new LineSegment(pE, pF);
	cout << pLS1 << endl << endl;

	LineSegment* pLS2 = new LineSegment(pE, pFPrime);
	cout << pLS2 << endl << endl;

	LineSegment* pLS3 = new LineSegment(pF);
	cout << pLS3 << endl << endl;

	LineSegment* pLS4 = new LineSegment(pE, pG);
	cout << pLS4 << endl << endl;

	LineSegment* pLS5 = new LineSegment(pSLO);
	cout << pLS5 << endl << endl;

	LineSegment* pLS6 = new LineSegment(pSL2);
	cout << pLS6 << endl << endl;

	LineSegment* pLS7 = new LineSegment(pD, pC);
	cout << pLS7 << endl << endl;

	LineSegment* pLS8 = new LineSegment(pC, pD);
	cout << pLS7 << endl << endl;


	cout << "LS6(C,D) == LS7(D,C): ";
	if (*pLS6 == pLS7)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS7(D,C) == LS6(C,D): ";
	if (*pLS7 == pLS6)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS6(D,C) == SL2(C,D): ";
	if (*pLS6 == pSL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS7(D,C) == SL2(C,D): ";
	if (*pLS7 == pSL2)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS8(C,D) == LS4(E,G) - Same StraigtLine, is LineSegment the same?: ";
	if (*pLS8 == pLS4)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	StraightLine* pSL3 = new StraightLine(pE, pG);
	cout << "SL2(C,D) == SL3(E,G) - Comparison with two StraigthLine object on different points: ";
	if (*pSL2 == pSL3)
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	cout << "Polymorphism test with a collection of StraightLine*, mixing StraightLine* & LineSegment* objects" << endl;
	cout << "Using the std::vector class of the C++ STL" << endl << endl;

	vector<StraightLine*> mySLStarCollection;
	mySLStarCollection.push_back(pLS6);
	mySLStarCollection.push_back(pLS7);
	mySLStarCollection.push_back(pSL2);
	mySLStarCollection.push_back(pSL3);

	cout << "LS6(C,D) {mySLStarCollection[0]} == LS7(D,C) {mySLStarCollection[1]} : ";
	if (*mySLStarCollection[0] == mySLStarCollection[1])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "LS6(C,D) {mySLStarCollection[0]} == SL2(C,D) {mySLStarCollection[2]} : ";
	if (*mySLStarCollection[0] == mySLStarCollection[2])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;


	cout << "LS6(C,D) {mySLStarCollection[0]} == SL3(E,G) {mySLStarCollection[3]} - Same StraightLine, different LineSegment" << endl;
	cout << "This should leverage FALSE, let's see: ";
	if (*mySLStarCollection[0] == mySLStarCollection[3])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "SL2(C,D) {mySLStarCollection[2]} == SL3(E,G) {mySLStarCollection[3]} - Same StraightLine, different points: ";
	if (*mySLStarCollection[2] == mySLStarCollection[3])
		cout << "TRUE";
	else
		cout << "FALSE";
	cout << endl << endl;

	cout << "Hurray! Polymorphism works!" << endl << endl;


	//IMPORTANT - ITERATING THROUGH THE VECTOR WITH AN ITERATOR OBJECT (STL)
	// this class has many capacities and many operators overload to use them
	// as the operator ++ used in the for loop below!
	vector<StraightLine*>::iterator objSLStarIterator;

	for (objSLStarIterator = mySLStarCollection.begin(); objSLStarIterator != mySLStarCollection.end(); objSLStarIterator++)
	{
		//An STL iterator is an pointer on the underlying collection element
		//Here, the collection is a vector<StraightLine*>
		//Taking the star (*) of an iterator instance, such as here *objIterator, provides a StraightLine*
		//or whichever type the collection is made of;
		// Having the operator << overload here is immensely useful
		// and of course, polymorphism just works :)
		cout << *objSLStarIterator << endl;
	}
	cout << endl;


	cout << "************* End of ex. dynamically allocated objects in the heap *************" << endl << endl << endl << endl;


	cout << "************************* Let's build Polygonal Chains! *************************" << endl << endl;

	cout << "********************* Example with few stack points *********************" << endl << endl;
	vector<Point2D> myStackPointsCollection;

	Point2D A1(1, 1, "A1");
	Point2D B1(6, 5, "B1");
	Point2D C1(0, 0, "C1");
	Point2D D1(-2, 1, "D1");
	Point2D E1(-2, 0, "E1");
	Point2D F1(5, 10, "F1");
	Point2D G1(9, -5, "G1");


	myStackPointsCollection.push_back(A1);
	myStackPointsCollection.push_back(B1);
	myStackPointsCollection.push_back(C1);
	myStackPointsCollection.push_back(D1);
	myStackPointsCollection.push_back(E1);
	myStackPointsCollection.push_back(F1);
	myStackPointsCollection.push_back(G1);


	PolygonalChain_Seb PolygChain1(myStackPointsCollection);
	cout << PolygChain1 << endl;

	cout << "********************* End of ex. with few stack points *********************" << endl << endl;



	cout << "********************* Example with few heap points *********************" << endl << endl;

	vector<Point2D*> myDynamicPointsCollection;
	Point2D* pA1 = new Point2D(1, 1, "A1");
	Point2D* pB1 = new Point2D(6, 5, "B1");
	Point2D* pC1 = new Point2D(0, 0, "C1");
	Point2D* pD1 = new Point2D(-2, 1, "D1");
	Point2D* pE1 = new Point2D(-2, 0, "E1");
	Point2D* pF1 = new Point2D(5, 10, "F1");
	Point2D* pG1 = new Point2D(9, -5, "G1");


	myDynamicPointsCollection.push_back(pA1);
	myDynamicPointsCollection.push_back(pB1);
	myDynamicPointsCollection.push_back(pC1);
	myDynamicPointsCollection.push_back(pD1);
	myDynamicPointsCollection.push_back(pE1);
	myDynamicPointsCollection.push_back(pF1);
	myDynamicPointsCollection.push_back(pG1);


	PolygonalChain_Seb PolygChain2(myDynamicPointsCollection);
	cout << PolygChain2 << endl;

	cout << "********************* End of ex. with few heap points *********************" << endl << endl;


	cout << "********************* Example with " << to_string(__NUMBER_OF_RANDOM_POINTS__)
		<< " randomly generated points *********************" << endl << endl;

	//This sample uses a random device equipped with a 64-bit Mersenne Twister Pseudo-Random Number generator
	// to feed a uniform distribution between -1 and 1, real valued
	// All these come from the <random> section of the C++ STL
	std::random_device objRandomDevice;
	std::mt19937_64 objRandomGenerator(objRandomDevice());
	std::uniform_real_distribution<> objRandomUsingDistribution(-1, 1);

	vector<Point2D*> myDynamicRandomPointsCollection;
	for (unsigned int i = 0; i < __NUMBER_OF_RANDOM_POINTS__; i++)
	{
		stringstream strStream;
		strStream << "P" << i;

		double currentBaseRandomX = objRandomUsingDistribution(objRandomGenerator) * 10;
		double currentBaseRandomX_down = floor(currentBaseRandomX * 100) / 100;
		double currentBaseRandomX_nearest = round(currentBaseRandomX * 100) / 100;

		double currentBaseRandomY = objRandomUsingDistribution(objRandomGenerator) * 10;
		double currentBaseRandomY_down = floor(currentBaseRandomX * 100) / 100;
		double currentBaseRandomY_nearest = round(currentBaseRandomY * 100) / 100;

		myDynamicRandomPointsCollection.push_back(new Point2D(currentBaseRandomX_nearest, currentBaseRandomY_nearest, strStream.str()));
	}

	PolygonalChain_Seb PolygChain3(myDynamicRandomPointsCollection);
	cout << PolygChain3 << endl;

	cout << "********************* End of ex. with " << to_string(__NUMBER_OF_RANDOM_POINTS__)
		<< " randomly generated points *********************" << endl << endl;


	delete pLS1;
	delete pLS2;
	delete pLS3;
	delete pLS4;
	delete pLS5;
	delete pLS6;
	delete pLS7;
	delete pLS8;

	delete pSLO;
	delete pSL1;
	delete pSL2;
	delete pSL3;

	delete pA;
	delete pB;
	delete pBPrime;
	delete pBSecond;
	delete pC;
	delete pD;
	delete pE;
	delete pF;
	delete pFPrime;
	delete pG;

	cout << "************* End of example after deallocation *************" << endl << endl;


	system("pause");
	return 0;
}
