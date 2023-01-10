// Copyright (c) 2015-2023 Dr. Colin Hirsch and Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/json/

#include "test.hpp"

#include <tao/json/from_string.hpp>
#include <tao/json/to_string.hpp>
#include <tao/json/value.hpp>

namespace tao::json
{
   [[nodiscard]] double string2double( const std::string& s )
   {
      return json::from_string( s ).get_double();
   }

   [[nodiscard]] std::string double2string( const double v )
   {
      return json::to_string( json::value( v ) );
   }

   void test_double( const std::string& s, const double v, const std::string& r )
   {
      TEST_ASSERT( v == string2double( s ) );
      TEST_ASSERT( r == double2string( v ) );
   }

   void unit_test()
   {
      test_double( "0.0", 0.0, "0.0" );
      test_double( "-0.0", -0.0, "-0.0" );
      test_double( "1.0", 1.0, "1.0" );
      test_double( "-1.0", -1.0, "-1.0" );
      test_double( "1.5", 1.5, "1.5" );
      test_double( "-1.5", -1.5, "-1.5" );
      test_double( "0.000", 0.0, "0.0" );
      test_double( "-0.000", -0.0, "-0.0" );
      test_double( "0.0001", 0.0001, "0.0001" );
      test_double( "-0.0001", -0.0001, "-0.0001" );
      test_double( "3.1416", 3.1416, "3.1416" );
      test_double( "0E10", 0.0, "0.0" );
      test_double( "0E+10", 0.0, "0.0" );
      test_double( "0E-10", 0.0, "0.0" );
      test_double( "0.00E10", 0.0, "0.0" );
      test_double( "0.00E+10", 0.0, "0.0" );
      test_double( "0.00E-10", 0.0, "0.0" );
      test_double( "0.00E0", 0.0, "0.0" );
      test_double( "0.00E+0", 0.0, "0.0" );
      test_double( "0.00E-0", 0.0, "0.0" );
      test_double( "0.00E000", 0.0, "0.0" );
      test_double( "0.00E+000", 0.0, "0.0" );
      test_double( "0.00E-000", 0.0, "0.0" );
      test_double( "1.000E0000", 1.0, "1.0" );
      test_double( "1.000E+0000", 1.0, "1.0" );
      test_double( "1.000E-0000", 1.0, "1.0" );
      test_double( "1.000E00001", 10.0, "10.0" );
      test_double( "1.000E+00001", 10.0, "10.0" );
      test_double( "1.000E-00001", 0.1, "0.1" );
      test_double( "1.23", 1.23, "1.23" );
      test_double( "1.234", 1.234, "1.234" );
      test_double( "1.2345", 1.2345, "1.2345" );
      test_double( "1.23456", 1.23456, "1.23456" );
      test_double( "1.234567", 1.234567, "1.234567" );
      test_double( "1.2345678", 1.2345678, "1.2345678" );
      test_double( "1.23456789", 1.23456789, "1.23456789" );
      test_double( "1.234567898", 1.234567898, "1.234567898" );
      test_double( "1.2345678987", 1.2345678987, "1.2345678987" );
      test_double( "1.23456789876", 1.23456789876, "1.23456789876" );
      test_double( "1.234567898765", 1.234567898765, "1.234567898765" );
      test_double( "1.2345678987654", 1.2345678987654, "1.2345678987654" );
      test_double( "1.23456789876543", 1.23456789876543, "1.23456789876543" );
      test_double( "1.234567898765432", 1.234567898765432, "1.234567898765432" );
      test_double( "-1.23", -1.23, "-1.23" );
      test_double( "-1.234", -1.234, "-1.234" );
      test_double( "-1.2345", -1.2345, "-1.2345" );
      test_double( "-1.23456", -1.23456, "-1.23456" );
      test_double( "-1.234567", -1.234567, "-1.234567" );
      test_double( "-1.2345678", -1.2345678, "-1.2345678" );
      test_double( "-1.23456789", -1.23456789, "-1.23456789" );
      test_double( "-1.234567898", -1.234567898, "-1.234567898" );
      test_double( "-1.2345678987", -1.2345678987, "-1.2345678987" );
      test_double( "-1.23456789876", -1.23456789876, "-1.23456789876" );
      test_double( "-1.234567898765", -1.234567898765, "-1.234567898765" );
      test_double( "-1.2345678987654", -1.2345678987654, "-1.2345678987654" );
      test_double( "-1.23456789876543", -1.23456789876543, "-1.23456789876543" );
      test_double( "-1.234567898765432", -1.234567898765432, "-1.234567898765432" );
      test_double( "1E-1", 1E-1, "0.1" );
      test_double( "1.2E-2", 1.2E-2, "0.012" );
      test_double( "1.23E-3", 1.23E-3, "0.00123" );
      test_double( "1.234E-4", 1.234E-4, "0.0001234" );
      test_double( "1.2345E-5", 1.2345E-5, "0.000012345" );
      test_double( "1.23456E-6", 1.23456E-6, "0.00000123456" );
      test_double( "1.234567E-7", 1.234567E-7, "1.234567e-7" );
      test_double( "1.2345678E-8", 1.2345678E-8, "1.2345678e-8" );
      test_double( "1.23456789E-9", 1.23456789E-9, "1.23456789e-9" );
      test_double( "1E10", 1E10, "10000000000.0" );
      test_double( "1e10", 1e10, "10000000000.0" );
      test_double( "1E+10", 1E+10, "10000000000.0" );
      test_double( "1E-10", 1E-10, "1e-10" );
      test_double( "-1E10", -1E10, "-10000000000.0" );
      test_double( "-1e10", -1e10, "-10000000000.0" );
      test_double( "-1E+10", -1E+10, "-10000000000.0" );
      test_double( "-1E-10", -1E-10, "-1e-10" );
      test_double( "1.234E+10", 1.234E+10, "12340000000.0" );
      test_double( "1.234E-10", 1.234E-10, "1.234e-10" );
      test_double( "1.79769e+308", 1.79769e+308, "1.79769e308" );
      test_double( "2.22507e-308", 2.22507e-308, "2.22507e-308" );
      test_double( "-1.79769e+308", -1.79769e+308, "-1.79769e308" );
      test_double( "-2.22507e-308", -2.22507e-308, "-2.22507e-308" );
      test_double( "4.9406564584124654e-324", 4.9406564584124654e-324, "5e-324" );
      test_double( "2.2250738585072009e-308", 2.2250738585072009e-308, "2.225073858507201e-308" );
      test_double( "2.2250738585072014e-308", 2.2250738585072014e-308, "2.2250738585072014e-308" );
      test_double( "1.7976931348623157e+308", 1.7976931348623157e+308, "1.7976931348623157e308" );
      test_double( "1e-10000", 0.0, "0.0" );
      test_double( "18446744073709551616", 18446744073709551616.0, "18446744073709552000.0" );
      test_double( "-9223372036854775809", -9223372036854775809.0, "-9223372036854776000.0" );
      test_double( "0.9868011474609375", 0.9868011474609375, "0.9868011474609375" );
      test_double( "123e34", 123e34, "1.23e36" );
      test_double( "45913141877270640000.0", 45913141877270640000.0, "45913141877270640000.0" );
      test_double( "2.2250738585072011e-308", 2.2250738585072011e-308, "2.225073858507201e-308" );
      test_double( "1e-214748363", 0.0, "0.0" );
      test_double( "1e-214748364", 0.0, "0.0" );
      test_double( "0.017976931348623157e+310", 1.7976931348623157e+308, "1.7976931348623157e308" );
      test_double( "2.2250738585072012e-308", 2.2250738585072014e-308, "2.2250738585072014e-308" );
      test_double( "2.22507385850720113605740979670913197593481954635164564e-308", 2.2250738585072009e-308, "2.225073858507201e-308" );
      test_double( "2.22507385850720113605740979670913197593481954635164565e-308", 2.2250738585072014e-308, "2.2250738585072014e-308" );
      test_double( "0.999999999999999944488848768742172978818416595458984375", 1.0, "1.0" );
      test_double( "0.999999999999999944488848768742172978818416595458984374", 0.99999999999999989, "0.9999999999999999" );
      test_double( "0.999999999999999944488848768742172978818416595458984376", 1.0, "1.0" );
      test_double( "1.00000000000000011102230246251565404236316680908203125", 1.0, "1.0" );
      test_double( "1.00000000000000011102230246251565404236316680908203124", 1.0, "1.0" );
      test_double( "1.00000000000000011102230246251565404236316680908203126", 1.00000000000000022, "1.0000000000000002" );
      test_double( "72057594037927928.0", 72057594037927928.0, "72057594037927930.0" );
      test_double( "72057594037927936.0", 72057594037927936.0, "72057594037927940.0" );
      test_double( "72057594037927932.0", 72057594037927936.0, "72057594037927940.0" );
      test_double( "7205759403792793199999e-5", 72057594037927928.0, "72057594037927930.0" );
      test_double( "7205759403792793200001e-5", 72057594037927936.0, "72057594037927940.0" );
      test_double( "9223372036854774784.0", 9223372036854774784.0, "9223372036854775000.0" );
      test_double( "9223372036854775808.0", 9223372036854775808.0, "9223372036854776000.0" );
      test_double( "9223372036854775296.0", 9223372036854775808.0, "9223372036854776000.0" );
      test_double( "922337203685477529599999e-5", 9223372036854774784.0, "9223372036854775000.0" );
      test_double( "922337203685477529600001e-5", 9223372036854775808.0, "9223372036854776000.0" );
      test_double( "10141204801825834086073718800384", 10141204801825834086073718800384.0, "1.0141204801825834e31" );
      test_double( "10141204801825835211973625643008", 10141204801825835211973625643008.0, "1.0141204801825835e31" );
      test_double( "10141204801825834649023672221696", 10141204801825835211973625643008.0, "1.0141204801825835e31" );
      test_double( "1014120480182583464902367222169599999e-5", 10141204801825834086073718800384.0, "1.0141204801825834e31" );
      test_double( "1014120480182583464902367222169600001e-5", 10141204801825835211973625643008.0, "1.0141204801825835e31" );
      test_double( "5708990770823838890407843763683279797179383808", 5708990770823838890407843763683279797179383808.0, "5.708990770823839e45" );
      test_double( "5708990770823839524233143877797980545530986496", 5708990770823839524233143877797980545530986496.0, "5.70899077082384e45" );
      test_double( "5708990770823839207320493820740630171355185152", 5708990770823839524233143877797980545530986496.0, "5.70899077082384e45" );
      test_double( "5708990770823839207320493820740630171355185151999e-3", 5708990770823838890407843763683279797179383808.0, "5.708990770823839e45" );
      test_double( "5708990770823839207320493820740630171355185152001e-3", 5708990770823839524233143877797980545530986496.0, "5.70899077082384e45" );
      test_double( "2.225073858507201136057409796709131975934819546351645648023426109724822222021076945516529523908135087914149158913039621106870086438694594645527657207407820621743379988141063267329253552286881372149012981122451451889849057222307285255133155755015914397476397983411801999323962548289017107081850690630666655994938275772572015763062690663332647565300009245888316433037779791869612049497390377829704905051080609940730262937128958950003583799967207254304360284078895771796150945516748243471030702609144621572289880258182545180325707018860872113128079512233426288368622321503775666622503982534335974568884423900265498198385487948292206894721689831099698365846814022854243330660339850886445804001034933970427567186443383770486037861622771738545623065874679014086723327636718751234567890123456789012345678901e-308", 2.2250738585072014e-308, "2.2250738585072014e-308" );
      test_double( "30e001", 300.0, "300.0" );

      // TODO: Disabled, triggers infinity
      // test_double( std::string( 2000, '1' ), (std::numeric_limits< double >::max)() );

      TEST_THROWS( from_string( "1.0e1234567890" ) );
      TEST_THROWS( from_string( std::string( 1048577, '1' ) ) );
      {
         const value v = from_string( "42.0" );
         const auto a = v.as< double >();
         TEST_ASSERT( a == 42.0 );
      }
      {
         const value v = from_string( "42.3" );
         const auto a = v.as< short >();
         TEST_ASSERT( a == 42 );
      }
      {
         const value v = from_string( "42" );
         const auto a = v.as< double >();
         TEST_ASSERT( a == 42.0 );
      }
      TEST_THROWS( value( "foo" ).as< double >() );
      TEST_THROWS( value( "bar" ).as< int >() );
   }

}  // namespace tao::json

#include "main.hpp"
