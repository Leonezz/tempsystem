var xData = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31];
var yData = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
    21, 22, 23];

var option =
{
    grid: [{
        top: '10%',
        width: '90%',
        height: '90%',
        bottom: 0,
        left: '5%',
        containLabel: true
    }],
    title: [
        {
            left: '40%',
            top: 0,
            text: '温度检测图',
            subtext: 'Target Temperature Map.',
        }],

    xAxis: [{
        data: xData,
    }],
    yAxis: [
        {
            data: yData,
        }],
    tooltip:
    {

    },
    toolbox:
    {
        gridIndex: 0,
        show: true,
        feature:
        {
            mark:
            {

                show: true
            },
            dataView:
            {
                show: true,
                readOnly: false
            },
            restore:
            {
                show: true
            },
            saveAsImage:
            {
                show: true
            }
        }
    },
    series: [
        {
            type: 'heatmap',
            name: 'TargetTemperature',
            align: 'left',
            data: [],
            itemStyle:
            {
                emphasis:
                {
                    borderWidth: 0
                }
            }
        }],
    visualMap:
    {
        gridIndex: 0,
        type: 'continuous',
        inRange:
        {
            color: ['#313695', '#4575b4', '#74add1', '#abd9e9', '#e0f3f8', '#ffffbf', '#fee090', '#fdae61', '#f46d43', '#d73027', '#a50026']
        },
        align: 'left',
        bottom: '5%',
        left: 0,
        itemWidth: 20,
        //calculable: true
    },

}