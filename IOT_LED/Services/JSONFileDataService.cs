using IOT_LED.Models;
using Microsoft.AspNetCore.Hosting;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;

namespace IOT_LED.Services
{
    public class JSONFileDataService
    {
        public JSONFileDataService(IWebHostEnvironment webHostEnvironment)
        {
            WebHostEnvironment = webHostEnvironment;
        }

        public IWebHostEnvironment WebHostEnvironment { get; }

        private string FilePath
        {
            get { return Path.Combine(WebHostEnvironment.WebRootPath, "data", "data.json"); }
        }

        public Data GetData()
        {
            using (var jsonFileReader = File.OpenText(FilePath))
            {
                return JsonSerializer.Deserialize<Data>(jsonFileReader.ReadToEnd(),
                    new JsonSerializerOptions
                    {
                        PropertyNameCaseInsensitive = true
                    });
            }
        }

        public void SetButton(string value)
        {
            var data = GetData();

            data.Button = value;

            string json = JsonSerializer.Serialize<Data>(data);
            File.WriteAllText(FilePath, json);
        }
    }
}
