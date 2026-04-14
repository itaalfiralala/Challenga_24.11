using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


[TestFixture]
public class UserTests
{
    [Test]
    public void IsValidUser()
    {
        User user = new User();
        Assert.IsTrue(user.IsValidUser("admin", "admin"));
    }
}