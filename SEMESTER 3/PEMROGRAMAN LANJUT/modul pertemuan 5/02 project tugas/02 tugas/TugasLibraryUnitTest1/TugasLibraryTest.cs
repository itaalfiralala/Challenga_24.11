using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;
using TugasLibrary; 

namespace TugasLibraryUnitTest1
{
    [TestFixture] 
    public class DayTest
    {
        [Test] 
        public void TestNameOfDay_ValidInput()
        {
            Day day = new Day();
           
            string result = day.NameOfDay(1);

           
            Assert.AreEqual("Minggu", result, "Hari ke-1 seharusnya adalah Minggu.");
        }

        [Test]
        public void TestNameOfDay_InvalidInput()
        {
            Day day = new Day();

           
            string result = day.NameOfDay(9);

          
            Assert.AreEqual("Input tidak valid", result, "Untuk input 9, harus mengembalikan 'Input tidak valid'.");
        }
    }
}
