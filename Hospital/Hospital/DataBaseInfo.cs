using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Hospital
{
	class DataBaseInfo
	{
		public static string GetConnectionInfoMS()
		{
			return "server=ISRAELLSMT_M\\SQLEXPRESS;database=hospital;Trusted_Connection=yes";
		}
		public static string GetConnectionInfoOracle()
		{
			//return "Data Source=XE;server=localhost;uid=hospital;pwd=1234;sid=XE;Integrated Security=yes";
			return "Data Source=XE;User Id=hospital;Password=1234;";//Unicode=True;
		}
	}
}
