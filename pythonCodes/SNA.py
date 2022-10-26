import pandas as pd
import openpyxl
import pickle
import re
import graphviz
from graphviz import Digraph,Graph
from collections import defaultdict
ff = open('graphvizData_temp.txt', 'rb')
Data = pickle.load(ff)
# print(Data)

edgelist = []
edgedict = dict()
for jobname,jobdata in Data.items():
    edgedict[jobname] = []
    
    for input_file in Data[jobname]['input_files']:
        edgelist.append((jobname,input_file))
        edgedict[jobname].append(input_file)
    for output_file in Data[jobname]['output_files']:
        edgelist.append((output_file,jobname))

nodelist = [job for job in edgedict]

for jobs in Data.keys():
    for ifile in Data[jobs]['input_files']:
        nodelist.append(ifile)
    for ofile in Data[jobs]['output_files']:
        nodelist.append(ofile)

# print("NODE LIST.......")        
# print(set(nodelist))
# print()
# print()
# print("ADJECENCY LIST.......")        
# print(edgedict)
# print()
# print()
# print("EDGE LIST.......") 
# print(edgelist)
df1=pd.DataFrame(edgelist)
# print(df1)
df1.to_excel('SNA1.xlsx', sheet_name='edgeList')
df2=pd.DataFrame(set(nodelist))
# print(df2)
df2.to_excel('SNA2.xlsx', sheet_name='nodeList')





# jobs = list(data.keys())
# graph_data = defaultdict(set)
# nodes = [0 for _ in range(len(jobs))]
# gg = Digraph(name="graph0" )
# gg.graph_attr['rankdir'] = 'LR'
# for i in range(len(jobs)):
#     nodes[i] = jobs[i]
#     job_data = data[nodes[i]]
#     nodes[i] = re.sub('[.*]+', '-', nodes[i])
#     # print(nodes[i], '::', job_data)
#     #gg.node(nodes[i], shape = 'square')
#     for filename in job_data['input_files']:
#         gg.node(nodes[i], shape = 'box')
#         gg.edge(re.sub('[.:*]+', '-', filename),nodes[i] , color='red')
#     for output in job_data['output_files']:
#         gg.node(nodes[i], shape = 'box')
#         gg.edge(nodes[i], re.sub('[.:*]+', '-', output), color='blue')

#     for filename in job_data['input_files']:
#         graph_data[nodes[i]].add((re.sub('[.:*-]+', '_', filename), False))
#         graph_data[filename].add((re.sub('[.:*-]+', '_', nodes[i]), True))
#     for filename in job_data['output_files']:
#         graph_data[nodes[i]].add((re.sub('[.:*-]+', '_', filename), True))
#         graph_data[filename].add((re.sub('[.:*-]+', '_', nodes[i]), False))
# # graph.view()
# #gg.render(filename='node_based', format='svg', view=True)

# def draw_graph(job_name, depth, graph_data,rank='TB'):
#     g = Digraph(name = "graph1")
#     g.graph_attr['rankdir'] = rank
#     nodes = [job_name]
#     visited = set()
#     for _ in range(depth):
#         new_nodes = set()
#         for node in nodes:
#             if node in visited:
#                 continue
#             for connection in graph_data[node]:
#                 node1, node2 = (node, connection[0]) if connection[1] else( connection[0], node)
#                # print(node1,";;;;",node2)
#                # g.attr('node', shape='box')
#                 g.node(node1, shape='square')
#                 g.edge(node1 , node2, color='red')
#                 new_nodes.add(connection[0])
#             visited.add(node)
#         nodes = new_nodes
#     #g.view()
#     #g.render(filename='node_based', format='svg', view=True)

# #draw_graph(jobs[11],2,graph_data)


# # "node" -> [ ("node2", onto?), ...]
# # "node2" -> [ ("node", !to?), ...]

# def dsfile_with_no_out_edges(data):
#     files = []
#     temp = []
#     for i in range(len(jobs)):
#         nodes[i] = jobs[i]
#         job_data = data[nodes[i]]
#         for file in job_data['input_files']:
#             files.append(file)
#     for i in range(len(jobs)):
#         nodes[i] = jobs[i]
#         job_data = data[nodes[i]]
#         for j in job_data['output_files']:
#             if j in files:
#                 pass
#             else :
#                 temp.append(j)
#     return temp