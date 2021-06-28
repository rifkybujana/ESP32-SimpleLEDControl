using System;
using System.Collections.Generic;
using System.Linq;
using System.Text.Json;
using System.Threading.Tasks;

namespace IOT_LED.Models
{
    public class Data
    {
        public string Button { get; set; }

        public override string ToString() => JsonSerializer.Serialize<Data>(this);
    }
}
