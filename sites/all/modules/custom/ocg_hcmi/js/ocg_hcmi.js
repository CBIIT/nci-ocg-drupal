async function getbuckets() {
  try {
    let res = await fetch('https://hcmi-searchable-catalog.nci.nih.gov/api/hcmi/graphql', {
      method: 'POST',
      headers: {'Content-Type': 'application/json'},
      body: JSON.stringify({query: 'query{models{hits{total}aggregations(aggregations_filter_themselves: true){primary_site{buckets{doc_count key key_as_string}}}}}'
      })
    });
    return await res.json();
  } catch (error) {
    console.log(error);
  }
}

async function renderBuckets() {
  let data = await getbuckets();
  let buckets = data.data.models.aggregations.primary_site.buckets;
  let urlStart = 'https://hcmi-searchable-catalog.nci.nih.gov/?query=%7B%20models%20%7B%20hits%20%7B%20total%20%7D%20aggregations%28%20aggregations_filter_themselves%3A%20true%20%29%20%7B%20primary_site%20%7B%20buckets%20%7B%20doc_count%20key%20key_as_string%20%7D%20%7D%20%7D%20%7D%20%7D&sqon=%7B%22op%22%3A%22and%22%2C%22content%22%3A%5B%7B%22op%22%3A%22in%22%2C%22content%22%3A%7B%22field%22%3A%22expanded%22%2C%22value%22%3A%5B%22true%22%5D%7D%7D%2C%7B%22op%22%3A%22in%22%2C%22content%22%3A%7B%22field%22%3A%22primary_site%22%2C%22value%22%3A%5B%22';
  let urlEnd = '%22%5D%7D%7D%5D%7D';
  let total = data.data.models.hits.total;

  buckets.forEach(function (d) {
    d.doc_count = +d.doc_count;
  });

  var color = d3.scale.ordinal()
          .range(["#448aff", "#fdd835", "#f06292", "#aeea00", "#7e57c2", "#80deea", "#ff9100", "#8c9eff", "#c51162", "#81d4fa", "#ffff00", "#388e3c", "#f8bbd0", "#2962ff", "#d1c4e9", "#d81b60", "#5d4037", "#80cbc4"]);

  var width = 200;
  var height = 200;
  var pie = d3.layout.pie().sort(null).value(function (d) {
    return d.doc_count;
  });

  var arc = d3.svg.arc()
          .outerRadius(width / 2 * 0.9)
          .innerRadius(width / 2 * 0.5)
  var svg = d3.select('donut').append('svg')
          .attr({width: width, height: height})
          .append('g')
          .attr('transform', 'translate(' + width / 2 + ',' + height / 2 + ')');

  svg.selectAll('path').data(pie(buckets))
          .enter().append('a')
          .attr("alt", function (d, i) {
            return buckets[i].key;
          })
          .attr("xlink:href", function (d, i) {
            return urlStart + buckets[i].key + urlEnd;
          })
          .append('path')
          .style('stroke', 'white')
          .attr('d', arc)
          .attr('fill', function (d, i) {
            return color(i);
          })
          .append("svg:title").text(function (d, i) {
    return buckets[i].key + " " + buckets[i].doc_count + " Models";
  });

  document.getElementById("total").innerHTML = total + " Models";

}

renderBuckets();