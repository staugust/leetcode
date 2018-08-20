import boto.s3.connection

access_key = 'CKI2I542T8XM55I7BDE3'
secret_key = '2kHmBPI2M7ISsutpgouXPDxpKFaj9x4awThRNBzZ'
conn = boto.connect_s3(
    aws_access_key_id=access_key,
    aws_secret_access_key=secret_key,
    host='10.0.2.45', port=7480,
    is_secure=False, calling_format=boto.s3.connection.OrdinaryCallingFormat(),
)

bucket = conn.create_bucket('aug')
for key in bucket.list():
    print(key)
    for ls in bucket.list(key.name):
        print(ls)


for bucket in conn.get_all_buckets():
    print("{name}".format(
        name=bucket.name,
        created=bucket.creation_date,
    ))

