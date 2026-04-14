using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

Code Day:

namespace TugasLibraryUnitTest2
{
    [TestFixture]
    public class DayTests
    {
        private Day day;

        [SetUp]
        public void Setup()
        {
            day = new Day();
        }

        [Test]
        public void NameOfDay()
        {
            string result = day.NameOfDay(1);
            Assert.AreEqual("Senin", result);


        }
    }
}
