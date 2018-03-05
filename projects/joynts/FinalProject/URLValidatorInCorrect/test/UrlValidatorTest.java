

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   UrlValidator urlVal = new UrlValidator(null, null, UrlValidator.ALLOW_ALL_SCHEMES);
	   Random ran = new Random();

	   for(int i = 0;i<10000;i++)
	   {	   
			int schemaIndex = ran.nextInt(testSchemas.length);
			int hostIndex = ran.nextInt(testHosts.length);
			int portIndex = ran.nextInt(testPorts.length);
			int pathIndex = ran.nextInt(testPaths.length);
			int queryIndex = ran.nextInt(testQueries.length);
			int fragmentIndex = ran.nextInt(testFragments.length);
			ResultPair url = URLmaker(schemaIndex, hostIndex, portIndex, pathIndex, queryIndex, fragmentIndex);
			System.out.println(String.format("Generated url: %s. is valid: %s", url.item, url.valid));
			assertEquals(url.valid, urlVal.isValid(url.item));
		}

   }
  
	//Schemas
	ResultPair[] testSchemas = {
		   new ResultPair("http://", true),
		   new ResultPair("https://", true),
		   new ResultPair("ftp://", true),
		   new ResultPair("bob://", true),
		   new ResultPair("ft.p://", true),
		   new ResultPair("ht-tp://", true),
		   new ResultPair("ht+tp://", true),
		   new ResultPair("http123://", true),
		   new ResultPair("123http://", false),
		   new ResultPair("+http://", false),
		   new ResultPair("-http://", false),
		   new ResultPair(".http://", false),
		   new ResultPair("http:////", false),
		   new ResultPair("http//", false),
		   new ResultPair("http:/", false),
		   new ResultPair("", false), 	// Should be true
		   new ResultPair("://", false)
	};
	//Hosts
	ResultPair[] testHosts = {
		   new ResultPair("www.amazon.com", true),
		   new ResultPair("www.bing.com", true),
		   new ResultPair("127.0.0.1", true),
		   new ResultPair("amazon.com", true),
		   new ResultPair("flip.engr.oregonstate.edu", true),
		   new ResultPair("www.amazon-is-great.com", true),
		   new ResultPair("foo.gov", true),
		   new ResultPair("foo.biz", true),
		   new ResultPair("foo.arpa", true),
		   new ResultPair("foo.edu", true),
		   new ResultPair("foo.mil", true),
		   new ResultPair("foo.ai", true),
		   new ResultPair("foo.bd", true),
		   new ResultPair("user@foo.gov", false),	//Should be true
		   new ResultPair("user:pass@foo.gov", false),	//Should be true
		   new ResultPair("", false),
		   new ResultPair("amazon", false),
		   new ResultPair("amazon.", false),
		   new ResultPair(".amazon", false),
		   new ResultPair("www.amazon", false),
		   new ResultPair("amazon com", false),
		   new ResultPair("www.amazon_is_great.com", false),
		   new ResultPair("www.amazon-is-great!.com", false),
		   new ResultPair("www.amazon%20is%20great.com", false),
		   new ResultPair("127..0.1", false),
		   new ResultPair("127.1", false),
		   new ResultPair(".127.0.0.1", false),
		   new ResultPair("256.0.0.1", true),	//Should be false
		   new ResultPair("127", false)
	};
	//Port Numbers
	ResultPair[] testPorts = {
		   new ResultPair("", true),
		   new ResultPair(":80", true),
		   new ResultPair(":8080", false),	//Should be true
		   new ResultPair(":65535", false),   //Should be true
		   new ResultPair(":65536", false),
		   new ResultPair(":24b", false),
		   new ResultPair(":-80", false),
		   new ResultPair(":AA", false)
	};
	//Paths,  should start with slash
	ResultPair[] testPaths = {
		   new ResultPair("", true),
		   new ResultPair("/path", true),
		   new ResultPair("/path/name", true), 
		   new ResultPair("/path2/../path1", true),
		   new ResultPair("/path2/..path1", false),
		   new ResultPair("/name;v=1.1", true),
		   new ResultPair("/name,v=1.1", true)
	};
	//Queries 
	ResultPair[] testQueries = {
		   new ResultPair("", true),
		   new ResultPair("?lvalue=rvalue", false),	//Should be true
		   new ResultPair("?lvalue=rvalue&lvalue2=rvalue2", false),	//Should be true
		   new ResultPair("?lvalue=rvalue:lvalue2=rvalue2", false), //Should be true
		   new ResultPair("?=rvalueonly", false)  //Should be true
	};   
	//Fragments
	ResultPair[] testFragments = {
			new ResultPair("", true),
			new ResultPair("#top", true),
			new ResultPair("#top/one/two", true),
			new ResultPair("#bottom?top", true),
			new ResultPair("#top..bottom", true),
			new ResultPair("#123", true)
	};
   


}
