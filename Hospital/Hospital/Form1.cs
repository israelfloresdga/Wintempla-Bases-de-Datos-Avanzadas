using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.SqlClient; //<<ADDED
using Oracle.DataAccess.Client; //Oracle. Add reference
//using System.Data.OracleClient;

namespace Hospital
{
	public partial class Form1 : Form
	{
		public Form1()
		{
			InitializeComponent();
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			Text = "Hospital";
			//___Check Box
			cbPatient.Enabled = true;
			cbPatient.DropDownStyle = ComboBoxStyle.DropDownList;
			//radioButton_MS.Checked = true;
			//radioButton_Oracle.Checked = false;
			//FillCbPatientMS();
			////radioButton_Oracle.Enabled = false; //DEBUG
		}

		private void radioButton_MS_Click(object sender, EventArgs e)
		{
			radioButton_MS.Checked = true;
			radioButton_Oracle.Checked = false;
			radioButton_MS.Enabled = false;
			radioButton_Oracle.Enabled = true;
			FillCbPatientMS();
		}

		private void radioButton_Oracle_Click(object sender, EventArgs e)
		{
			radioButton_MS.Checked = false;
			radioButton_Oracle.Checked = true;
			radioButton_MS.Enabled = true;
			radioButton_Oracle.Enabled = false;
			FillCbPatientOracle();
		}

		private void FillCbPatientMS()
		{
			cbPatient.DataSource = null;
			if (cbPatient.Items.Count > 0) { cbPatient.Items.Clear(); }
			//__Connection
			SqlConnection conn = new SqlConnection(Hospital.DataBaseInfo.GetConnectionInfoMS());
			SqlCommand cmd = null;
			SqlDataReader reader = null;
			cbPatient.DisplayMember = "displayData";
			cbPatient.ValueMember = "valueData";
			try
			{
				conn.Open();
				cmd = new SqlCommand("SELECT patient_id, name FROM patient", conn);
				reader = cmd.ExecuteReader();
				while (reader.Read())
				{
					cbPatient.Items.Add(new ListItems(reader.GetInt32(0), reader["name"].ToString()));
				}
				cbPatient.SelectedIndex = 0;
				//updateItems();
			}
			catch (SqlException ex)
			{
				MessageBox.Show(ex.Message, "Error");
			}
			finally
			{
				reader.Close();
				conn.Close();
				cbPatient.SelectedIndex = 0;
				//updateItems();
			}
		}

		private void FillCbPatientOracle()
		{
			if (cbPatient.Items.Count > 0) { cbPatient.Items.Clear(); cbPatient.Refresh(); }
			//__Connection
			OracleConnection conn = new OracleConnection(Hospital.DataBaseInfo.GetConnectionInfoOracle());
			OracleCommand cmd = null;
			OracleDataReader reader = null;
			cbPatient.DisplayMember = "displayData";
			cbPatient.ValueMember = "valueData";
			
			try
			{
				conn.Open();
				cmd = new OracleCommand("SELECT patient_id, name FROM patient", conn);
				reader = cmd.ExecuteReader();
				while (reader.Read())
				{
					cbPatient.Items.Add(new ListItems((Convert.ToInt32(reader.GetValue(0).ToString())), reader.GetValue(1).ToString()));
					//cbPatient.Items.Add(new ListItems(reader.GetInt32(0), reader["name"].ToString()));
					//cbPatient.Items.Add(new ListItems((int)reader.GetValue(0), reader.GetValue(1).ToString()));
					//}
					//DataTable dt = new DataTable();
					//OracleDataAdapter da = new OracleDataAdapter(cmd);
					//da.Fill(dt);
					//cbPatient.DataSource = dt;
					//cbPatient.ValueMember = "patient_id";
					//cbPatient.DisplayMember = "name";
				}
				cbPatient.SelectedIndex = 0;
				//updateItems();
			}
			catch (OracleException ex)
			{
				MessageBox.Show(ex.Message, "Error");
			}
			finally
			{
				reader.Close();
				conn.Close();
				cbPatient.SelectedIndex = 0;
				//updateItems();
			}
		}

		private void button_Generate_Click(object sender, EventArgs e)
		{
			if (cbPatient.Items.Count == 0) return;
			if (cbPatient.SelectedIndex < 0) return;
			int selectedIndex = (int)cbPatient.SelectedIndex;
			int patient_id = ((ListItems)cbPatient.Items[selectedIndex]).ValueData;
			//			
			if (radioButton_MS.Checked == true)
			{
				//if (cbPatient.Items.Count == 0) return;
				//if (cbPatient.SelectedIndex < 0) return;
				//int selectedIndex = (int)cbPatient.SelectedIndex;
				//int patient_id = ((ListItems)cbPatient.Items[selectedIndex]).ValueData;
				//
				RunProcedureMS(patient_id); 
			}
			else if (radioButton_Oracle.Checked == true)
			{
				//if (cbPatient.Items.Count == 0) return;
				//if (cbPatient.SelectedIndex < 0) return;
				//int selectedIndex = (int)cbPatient.SelectedIndex;
				//int patient_id = cbPatient.ValueMember[selectedIndex];
				//
				RunProcedureOracle(patient_id); 
			}
		}

		private void RunProcedureMS(int patient_id)
		{ 
			SqlConnection conn = new SqlConnection(Hospital.DataBaseInfo.GetConnectionInfoMS());
			SqlCommand cmd = null;
			SqlDataReader reader = null;
			Object return_value= 0;
			string stored_procedure = "p_insert_patient_visit";
			try
			{
				conn.Open();
				// 1. create a command object identifying the stored procedure
				cmd = new SqlCommand(stored_procedure,conn);
				// 2. set the command object so it knows to execute a stored procedure
				cmd.CommandType = CommandType.StoredProcedure;
				cmd.Parameters.Add(new SqlParameter("@in_patient_id", SqlDbType.Int)).Value= patient_id;
				//cmd.Parameters.AddWithValue("@in_patient_id", patient_id);
				//return_value = cmd.ExecuteScalar();	
				
				cmd.Parameters.Add("@out_patient_visit_id", SqlDbType.Int);
				cmd.Parameters["@out_patient_visit_id"].Direction = ParameterDirection.Output;
				cmd.ExecuteNonQuery();

				string message = cmd.Parameters["@out_patient_visit_id"].Value.ToString();

				MessageBox.Show("patient_visit_id= " + message);

				//sqlcomm.ExecuteNonQuery();
				//sqlcomm.Dispose(); 
			}
			catch (SqlException e)
			{
				MessageBox.Show(e.Message, "Error");
			}
			finally
			{
				//reader.Close();
				conn.Close();
			}

		}

		private void RunProcedureOracle(int patient_id)
		{
			OracleConnection conn = new OracleConnection(Hospital.DataBaseInfo.GetConnectionInfoOracle());
			OracleCommand cmd = null;
			//OracleDataReader reader = null;
			//Object return_value = 0;
			string stored_procedure = "p_insert_patient_visit";
			try
			{
				conn.Open();
				// 1. create a command object identifying the stored procedure
				cmd = new OracleCommand(stored_procedure, conn);
				// 2. set the command object so it knows to execute a stored procedure
				cmd.CommandType = CommandType.StoredProcedure;
				cmd.Parameters.Add(new OracleParameter("in_patient_id", OracleDbType.Int32)).Value = patient_id;
				//cmd.Parameters.AddWithValue("in_patient_id", patient_id);
				//return_value = cmd.ExecuteScalar();	

				cmd.Parameters.Add("out_patient_visit_id", OracleDbType.Int32);
				cmd.Parameters["out_patient_visit_id"].Direction = ParameterDirection.Output;
				cmd.ExecuteNonQuery();

				string message = cmd.Parameters["out_patient_visit_id"].Value.ToString();

				MessageBox.Show("patient_visit_id= " + message);

				//sqlcomm.ExecuteNonQuery();
				//sqlcomm.Dispose(); 
			}
			catch (OracleException e)
			{
				MessageBox.Show(e.Message, "Error");
			}
			finally
			{
				//reader.Close();
				conn.Close();
			}
		}
	}
}

